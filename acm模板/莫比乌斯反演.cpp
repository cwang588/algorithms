//莫比乌斯反演 
#include<bits/stdc++.h>
#define ll int
using namespace std;
const long long mod=20101009; 
const int N=1e7+5;
long long mob[N],vis[N],prime[N];
int tot;
//找[1,n],[1,m]内互质的数的对数，分块优化
ll f(ll n,ll m )
{
	if(!n||!m)return 0;
    if(n>m)swap(n,m);
    ll ret=0;
    for (int i=1,last;i<=n;i=last+1)
    {
        last=min(n/(n/i),m/(m/i));
        ret+=(mob[last]-mob[i-1])*(n/i)*(m/i);
    }
    return ret;
}
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
int main()
{
	int t;
	scanf("%d",&t);
	Mobius(50000);
	for(int i=1;i<=50000;++i)mob[i]+=mob[i-1];
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int ans=f(b/k,d/k)+f((a-1)/k,(c-1)/k)-f((a-1)/k,d/k)-f(b/k,(c-1)/k);
		printf("%d\n",ans);
	}
	return 0;
}
