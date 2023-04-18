#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll mu[1000005],prim[1000005];
ll cnt=0;
bool vis[1000005];
void getmu(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
			mu[i]=-1;
		} 
		for(int j=1;j<=cnt&&prim[j]*i<n;++j)
		{
			vis[prim[j]*i]=true;
			if(i%prim[j]==0)
				break;
			else
				mu[i*prim[j]]=-mu[i];
		}
	}
} 
int main()
{
	int n;
	scanf("%d",&n);
	getmu(50000);
	while(n--)	
	{
		ll a,b,d;
		scanf("%lld%lld%lld",&a,&b,&d);
		a/=d;
		b/=d;
		ll ans1,ans2;
		ans1=ans2=0;
		for(int i=1;i<=min(a,b);++i)
			ans1+=mu[i]*(a/i)*(b/i);
		for(int i=1;i<=min(a,b);++i)
			ans2+=mu[i]*(min(a,b)/i)*(min(a,b)/i);
		printf("%lld\n",ans1-ans2/2);
	}
	return 0;
}
