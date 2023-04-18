#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct point{
	int id,degree;
	bool operator < (const point &b)const
	{
		if(degree!=b.degree)return degree<b.degree;
		return id<b.id;
	} 
};
int cnt1;
int du[100005];
bool usd[100005],ans1[100005];
set<pair<int,int> >s;
void dfs(int now,int pre){
	++cnt1;
	ans1[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to]||ans1[to]||to==pre)continue;
		dfs(to,now);
	}
}
unordered_map<long long,bool>mm;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		cnt1=cnt=0;
		for(int i=1;i<=n;++i)Head[i]=0,du[i]=0,usd[i]=ans1[i]=false;
		for(int i=1;i<=m;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			++du[x],++du[y];
			mm[(long long)x*100000+y]=true;
			mm[(long long)y*100000+x]=true;
		}
		for(int i=1;i<=n;++i)s.insert(make_pair(du[i],i));
		bool ky=false;
		while(!s.empty()){
			int now=(*s.begin()).second;
			if(du[now]>=k){
				dfs(now,0);
				printf("1 %d\n",cnt1);
				for(int i=1;i<=n;++i)if(ans1[i])printf("%d ",i);
				printf("\n");
				ky=true;
				break;
			}
			if(du[now]==k-1&&k<=500){
				vector<int>pp;
				for(int i=Head[now];i;i=e[i].nxt){
					int to=e[i].to;
					if(usd[to])continue;
					pp.push_back(to);
				}
				pp.push_back(now);
				bool ky2=true;
				int len=pp.size();
				for(int i=0;i<len;++i){
					for(int j=i+1;j<len;++j){
						long long ttt=(long long)pp[i]*100000+pp[j];
						if(!mm[ttt]){
							ky2=false;
							break;
						}
					}
					if(!ky2)break;
				}
				if(ky2){
					printf("2\n");
					for(auto x:pp)printf("%d ",x);
					printf("\n");
					ky=true;
					break;
				}
			}
			s.erase(s.begin());
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				if(usd[to])continue;
				--du[to];
				pair<int,int>tmp={du[to]+1,to};
			//	auto del=s.lower_bound(tmp);
				s.erase(tmp);
				if(!du[to]){
					usd[to]=true;
					continue;
				}
				--tmp.first;
				s.insert(tmp);
			}
		}
		s.clear();
		mm.clear();
		if(!ky)printf("-1\n");
	}
	return 0;
}
