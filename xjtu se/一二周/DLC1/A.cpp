#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[600005];
int Head[300005],cnt;
const long long mod=998244353;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
} 
long long ans;
long long sum[300005]; 
void dfs(long long now,long long pre)
{
	long long tmp=0,tot=0;
	sum[now]=now;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		tot=(tot+tmp*sum[to]%mod)%mod;
		sum[now]=(sum[now]+sum[to])%mod;
		tmp=(tmp+sum[to])%mod;
	}
	ans=(ans+tot*2%mod*now)%mod;
	ans=(ans+((now*now)*2%mod*(sum[now]-now)%mod)%mod)%mod;
}
int main()
{
	//freopen("1.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(long long i=1;i<=n;++i)ans=(ans+(i*i*i)%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
