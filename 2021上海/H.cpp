#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N];
struct edge{
	int from,to,nxt;
	long long value;
}e[8*N];
int cnt,Head[N*5];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct bian{
	int x,y;
	long long z;
}b[100005];
bool cmp(bian p,bian q){
	return p.z<q.z;
}
int fa[3*N],n,m,q;
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
long long value[3*N],sum[3*N],dp[3*N][25],father[3*N][25];
void dfs(int now,int pre){
	father[now][0]=pre;
	for(int i=1;i<=20;++i)father[now][i]=father[father[now][i-1]][i-1];
	if(now<=n){
		sum[now]=a[now];
		return;
	}
	long long tmp=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to,now);
		dp[to][0]=value[now]-sum[to];
		sum[now]+=sum[to];
	}
}
void dfss(int now){
	for(int i=1;i<=20;++i)dp[now][i]=max(dp[now][i-1],dp[father[now][i-1]][i-1]);
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfss(to);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i].x>>b[i].y>>b[i].z;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=n*2;++i)fa[i]=i;
	int nodecnt=n;
	for(int i=1;i<=m;++i){
		int r1=getfa(b[i].x),r2=getfa(b[i].y);
		if(r1==r2)continue;
		++nodecnt;
		add(nodecnt,r1);
		add(nodecnt,r2);
		fa[r1]=fa[r2]=nodecnt;
		value[nodecnt]=b[i].z;
	}
	for(int i=0;i<=20;++i)dp[0][i]=1145141919810ll;
	dfs(nodecnt,nodecnt);
	dfss(nodecnt);
	
	for(int i=1;i<=q;++i){
		int x;
		long long qq;
		cin>>x>>qq;
		int now=x;
		for(int j=20;j>=0;--j){
			if(dp[now][j]<=qq)now=father[now][j];
		}
		cout<<sum[now]+qq<<"\n";
	}
	return 0;
}