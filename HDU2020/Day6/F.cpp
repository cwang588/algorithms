#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int a[100005];
struct edge
{
	int from,to,nxt;
	long long v;
}e[200005];
int Head[100005],cnt;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
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
int fa[100005],s;
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
long long tot[100005],num[100005],sum;
void dfs1(int now,int pre,long long totnow)
{
	num[now]=0;
	if(a[now]!=a[s])num[now]=1,tot[s]=(tot[s]+totnow)%mod;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now,(totnow+e[i].v)%mod);
		num[now]+=num[to];
	} 
} 
void dfs2(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		tot[to]=(tot[now]+(sum-2*num[to])%mod*e[i].v)%mod;
		dfs2(to,now);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=s=sum=0;
		memset(Head,0,sizeof(Head));
		memset(tot,0,sizeof(tot));
		memset(num,0,sizeof(num));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(s==0&&a[i]==1)s=i; 
			fa[i]=i;
		}
		for(int i=1;i<=n;++i)if(a[i]!=a[s])++sum;
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int r1=getfa(x),r2=getfa(y);
			if(r1!=r2)
			{
				long long tmp=quickpower(2,i,mod);
				add(x,y,tmp);
				add(y,x,tmp);
				Merge(r1,r2);
			}
		}
		if(!s)
		{
			printf("0\n");
			continue;
		}
		dfs1(s,0,0);
		dfs2(s,0);
		long long ans=0;
		for(int i=1;i<=n;++i)if(a[i]==a[s])ans=(ans+tot[i])%mod; 
		printf("%lld\n",(ans+mod)%mod);
	}
	return 0;
}
