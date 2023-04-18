#include<bits/stdc++.h>
using namespace std;
const long long mod=20101009; 
const int N=1e7+5;
long long mob[N],vis[N],prime[N],tep[N];
int tot;
void Mobius(int n)
{
    memset(prime,0,sizeof(prime));
    memset(mob,0,sizeof(mob));
    memset(vis,0,sizeof(vis));
    tot=0,mob[1]=1;
    for(int i=2;i<=n;++i)
	{
        if(!vis[i])
		{
            prime[tot++]=i;
            mob[i]=-1;
        }
        for(int j=0;j<tot&&i*prime[j]<=n;++j)
		{
            vis[i*prime[j]]=1;
            if(i%prime[j]) 
				mob[i*prime[j]]=-mob[i];
            else
			{
                mob[i*prime[j]] = 0;
                break;
            }
        }
    }
}
long long g(long long n,long long m)
{
	return ((n+1)*n/2%mod)*((m+1)*m/2%mod)%mod;
}
long long f(int n,int m)
{
	long long re=0;
	for(long long l=1,r;l<=min(n,m);l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		re=(re+(tep[r]-tep[l-1])%mod*g(n/l,m/l)%mod)%mod;
	}
	return re;
}
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	Mobius((int)max(n,m));
	for(long long i=1;i<=max(n,m);++i)tep[i]=(tep[i-1]+mob[i]*i*i%mod)%mod;
	long long ans=0;
	for(long long l=1,r;l<=min(n,m);l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		ans=(ans+(r-l+1)*(r+l)/2%mod*f(n/l,m/l)%mod)%mod;
	}
	while(ans<0)ans+=mod;
	printf("%lld\n",ans);
	return 0;
}
