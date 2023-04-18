#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y,nxt;
	long long value;
}ee[500005],e[500006];
int cnt,Head[10005],id[500005];
void add(int x,int y){
	++cnt;
	e[cnt].x=x;
	e[cnt].y=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[500005];
int fa[10005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
bool cmp1(edge a,edge b){
	return a.value>b.value;
}
bool cmp2(edge a,edge b){
	return a.value<b.value;
}
int dfs(int now,int pre){
	int num=1;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].y;
		if(to==pre||usd[i])continue;
		num+=dfs(to,now);
	}
	return num;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>ee[i].x>>ee[i].y>>ee[i].value;
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(ee+1,ee+1+m,cmp1);
	long long Min=2147483647;
	for(int i=1;i<=m;++i){
		int r1=getfa(ee[i].x),r2=getfa(ee[i].y);
		if(r1==r2)continue;
		Merge(r1,r2);
		Min=min(Min,ee[i].value);
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	long long ans=0;
	sort(ee+1,ee+1+m,cmp2);
	for(int i=1;i<=m;++i){
		int r1=getfa(ee[i].x),r2=getfa(ee[i].y);
		if(ee[i].value<Min||r1==r2)continue;
		Merge(r1,r2);
		add(ee[i].x,ee[i].y);
		add(ee[i].y,ee[i].x);
		id[i]=cnt;
	}
	for(int i=1;i<=m;++i){
		if(!id[i])continue;
		usd[id[i]-1]=usd[id[i]]=true;
		ans+=ee[i].value*dfs(ee[i].x,0)*dfs(ee[i].y,0);
	}
	cout<<ans<<endl;
	return 0;
}
