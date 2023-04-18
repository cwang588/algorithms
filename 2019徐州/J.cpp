#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1000006];
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
struct edge
{
	int from,to,nxt;
}e[2000006];
int Head[1000006];
int cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dep;
void dfs1(int now,int pre,int dp)
{
	dep=max(dep,dp);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		dfs1(e[i].to,now,dp+1);
	}
}
bool ky[1000006];
void dfs2(int now,int pre,int depth)
{
	if(dep==depth)
	{
		ky[now]=true;
		return;
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		dfs2(e[i].to,now,depth+1);
		if(ky[e[i].to])ky[now]=true;
	}
}
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
void dfs3(int now,int pre)
{
	long long num1=0,num2=0,tep=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		++num1;
		if(ky[e[i].to])++num2;
		else 
		{
			dfs3(e[i].to,now);
			tep=(tep+dp[e[i].to])%mod;
		}
	}
	if(!num1)
	{
		dp[now]=1;
		return;
	}
	dp[now]=quickpower(tep,num1,mod);
	long long ny=quickpower(num1,mod-2,mod);
	dp[now]=(dp[now]*quickpower(ny,num1,mod))%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	dfs3(1,0);
	printf("%lld\n",(mod+1-dp[1])%mod);
	return 0;
}
