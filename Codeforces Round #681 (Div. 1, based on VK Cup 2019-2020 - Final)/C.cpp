#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > qq;
struct edge{
	int from,to,nxt;
	long long value;
}e[200005*25],ee[200005],E[200005];
int Head[200005*25],HHead[200005],cnt,cntt,Cnt,Hd[200005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y,int z){
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].value=z;
	ee[cntt].nxt=HHead[x];
	HHead[x]=cntt;
}
bool usd[200005*25],used[200005];
long long dis[200005*25],diss[200005];
long long mi[200005];
bool tu[200005];
int rd[200005],dp[200005];
void dfs(int now){
	tu[now]=true;
	for(int i=Hd[now];i;i=E[i].nxt){
		int to=E[i].to;
		dfs(to);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	mi[0]=1;
	for(int i=1;i<=200000;++i)mi[i]=mi[i-1]*2%mod;
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addd(x,y,0);
		addd(y,x,1);
		for(int j=0;j<=21;++j){
			int nowx=x+j*n,nowy=y+j*n;
			add(nowx,nowy);
			if(j!=21)add(nowy,nowx+n);
		}
	}
	queue<int>q;
	q.push(1);
	usd[1]=true;
	for(int i=1;i<=n*21;++i)dis[i]=mod;
	dis[1]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			dis[to]=min(dis[to],dis[now]+1);
			if(!usd[to]){
				q.push(to);
				usd[to]=true;
			}
		}
	}
	long long ans=mod;
	for(int i=0;i<=20;++i)ans=min(ans,dis[(i+1)*n]+mi[i]-1);
	if(ans<mod)return !printf("%I64d\n",ans);
	for(int i=1;i<=n;++i)diss[i]=mod;
	dis[1]=0;
	qq.push(make_pair(0,1));
	while(!qq.empty())
	{
		int now=qq.top().second;
		qq.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=HHead[now];i;i=ee[i].nxt)
			{
				if(diss[ee[i].to]>diss[ee[i].from]+ee[i].value)
				{
					diss[ee[i].to]=diss[ee[i].from]+ee[i].value;
					qq.push(make_pair(diss[ee[i].to],ee[i].to));
				}
			}
		}	
	}
	for(int i=1;i<=cntt;++i){
		int x=ee[i].from,y=ee[i].to;
		if(dis[x]+ee[i].value==dis[y])E[++Cnt]=ee[i],E[Cnt].nxt=Hd[x],Hd[x]=Cnt;
	}
	dfs(1);
	for(int i=1;i<=Cnt;++i){
		int x=E[i].from,y=E[i].to;
		if(tu[x]&&tu[y])++rd[y];
	}
	for(int i=1;i<=n;++i)dp[i]=mod;
	dp[1]=0;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=Hd[now];i;i=E[i].nxt){
			int to=E[i].to;
			dp[to]=min(dp[to],dp[now]+(int)E[i].value);
			--rd[to];
			if(!rd[to])q.push(to);
		}
	}
	ans=mi[diss[n]];
	ans=(ans+dp[n]-1)%mod;
	printf("%I64d\n",ans);
	return 0;
}
