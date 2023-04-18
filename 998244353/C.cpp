#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y,value;
};
bool cmp(edge a,edge b){
	if(a.value!=b.value)return a.value>b.value;
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
pair<int,int>rp[40000007];
map<pair<int,int>,bool>usd;
struct network{
	vector<int>v;
	vector<int>sz;
	int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin();}
	int n,cnt;
	unsigned long long hash_value,hash_value2;
	vector<int>fa,depth;
	vector<vector<int> >f;
	vector<vector<int> >to;
	vector<edge>e;
	int getfa(int x){
		if(fa[x]!=x)fa[x]=getfa(fa[x]);
		return fa[x];
	}
	void init(int n){
		this->n=cnt=n;
		hash_value=hash_value2=0;
		for(int i=0;i<=n*2;++i){
			vector<int>tmp1;
			vector<int>tmp2(25);
			to.push_back(tmp1);
			f.push_back(tmp2);
			fa.push_back(i);
			depth.push_back(0);
		}
	}
	void add(int x,int y){
		to[x].push_back(y);	
	}
	priority_queue<int>q;
	int lca(int x,int y){
		if(depth[x]<depth[y])swap(x,y);
		for(int i=20;i>=0;--i)if(depth[f[x][i]]>=depth[y])x=f[x][i];
		if(x==y)return x;
		for(int i=20;i>=0;--i){
			if(f[x][i]!=f[y][i]){
				x=f[x][i];
				y=f[y][i];
			}
		}
		return f[x][0];
	}
	void dfs(int now,int pre){
		f[now][0]=pre;
		depth[now]=depth[pre]+1;
		for(int i=1;i<=20;++i)f[now][i]=f[f[now][i-1]][i-1];
		for(auto t:to[now])dfs(t,now);
	}
	void kruskal(){
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		sort(e.begin(),e.end(),cmp);
		for(auto now:e){
			int r1=getfa(now.x),r2=getfa(now.y);
			fa[r1]=fa[r2]=++cnt;
			add(cnt,r1);
			add(cnt,r2);
			hash_value2=hash_value2*998244353+now.value;
		}
		dfs(cnt,0);
		for(int i=1;i<=n;++i){
			hash_value=hash_value*19260817+e[lca(rp[i].first,rp[i].second)-n-1].value;
		}
	}	
}pipe[500005];
map<pair<unsigned long long,unsigned long long>,int>id;
int main(){
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	srand(time(0));
	int n,d;
	cin>>d>>n;
	for(int i=1;i<=20000000/d;++i){
		int x,y;
		while(true){
			x=rand()%n+1;
			y=rand()%n+1;
			auto nowp=make_pair(x,y);
			if(x!=y){
				rp[i]=nowp;
				break;
			}
		}
	}
	for(int i=1;i<=d;++i){
		pipe[i].init(n);
		for(int j=1;j<n;++j){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y)swap(x,y);
			pipe[i].e.push_back(edge{x,y,z});
			pipe[i].v.push_back(z);
		}
		pipe[i].kruskal();
	}
	for(int i=1;i<=d;++i){
		auto now=make_pair(pipe[i].hash_value,pipe[i].hash_value2);
		if(!id[now])id[now]=i;
		cout<<id[now]<<" ";
	}
	return 0;
}