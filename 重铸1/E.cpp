#include<bits/stdc++.h>
using namespace std;
vector<int>to[200005];
map<pair<int,int>,int>cnt;
int deg[200005];
void add(int x,int y){
	to[x].push_back(y);
}
char ss[200005];
int fa[200005];
stack<int>s;
void dfs(int now){
	for(int x:to[now]){
		int nowx=min(x,now),nowy=max(x,now);
		if(!cnt[make_pair(nowx,nowy)])continue;
		--cnt[make_pair(nowx,nowy)];
		dfs(x);
	}
	s.push(now);
} 
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
int ans[1000005],sum[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		add(x,y);
		add(y,x);
		++cnt[make_pair(x,y)];
		++deg[x];
		++deg[y];
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2)Merge(r1,r2);
	}
	cin>>(ss+1);
	for(int i=1;i<=n;++i)getfa(i);
	for(int i=1;i<=n;++i)++sum[fa[i]];
	int ltcnt=0,start;
	for(int i=1;i<=n;++i){
		if(fa[i]!=i)continue;
		if(deg[i]){
			++ltcnt;
			start=i;
			if(ltcnt>1)return !printf("No\n");
		}
	}
	long long tot1=0,tot2=0;
	for(int i=1;i<=n;++i){
		if(deg[i]%2)return !printf("No\n");
		if(ss[i]=='(')tot1+=deg[i];
		else tot2+=deg[i];
	}
	if(tot1!=tot2)return !printf("No\n");
//	for(int i=1;i<=n;++i)sort(to[i].begin(),to[i].end());
	dfs(start);
	int num=0;
	while(!s.empty()){
		ans[++num]=s.top();
		s.pop();
	}
	int now=0,Min=19260817,pos;
	for(int i=1;i<num;++i){
		if(ss[ans[i]]=='(')++now;
		else --now;
		if(now<Min){
			Min=now;
			pos=i+1;
		}
	}
	assert(ans[1]==ans[num]);
	cout<<"Yes\n";
	for(int i=pos;i<num;++i)cout<<ans[i]<<" ";
	for(int i=1;i<pos;++i)cout<<ans[i]<<" ";
	return 0;
}
