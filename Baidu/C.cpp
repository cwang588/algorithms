#include<bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long x,long long y)
{
	return x>y;
}
long long q[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l,k;
		scanf("%d%d%d",&n,&l,&k);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);	
		sort(a+1,a+1+n,cmp);
		long long ans1=0,ans2=0;
		int now=0;
		for(int i=l-k+1;i<=l;++i)q[i]=a[++now];
		ans1=q[l];
		long long last=q[l];
		for(int i=2;i+l-1<=n;++i)
		{
			if(!q[i-1])ans1+=last;
			else
			{
				q[i+l-1]=a[++now];
				ans1+=a[now];
				last=a[now];
			}
		}
		for(int i=1;i<=n;++i)q[i]=0;
		sort(a+1,a+1+n);
		k=l-k+1;
		now=0;
		for(int i=l-k+1;i<=l;++i)q[i]=a[++now];
		ans2=q[l];
		last=q[l];
		for(int i=2;i+l-1<=n;++i)
		{
			if(!q[i-1])ans2+=last;
			else
			{
				q[i+l-1]=a[++now];
				ans2+=a[now];
				last=a[now];
			}
		}
		printf("%lld %lld\n",ans1,ans2);
		for(int i=1;i<=n;++i)q[i]=0;
	}
	return 0;
}
