#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],sum1[100005],sum2[100005];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	int n,m,d;
	scanf("%d%d%d",&n,&d,&m);
	int l1=0,l2=0;
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		if(t<=m)a[++l1]=t;
		else b[++l2]=t;
	}
	sort(a+1,a+1+l1);
	sort(b+1,b+1+l2,cmp);
	long long ans=0;
	for(int i=1;i<=l1;++i)sum1[i]=sum1[i-1]+a[i];
	for(int i=1;i<=l2;++i)sum2[i]=sum2[i-1]+b[i];
	if(!l2)
	{
		for(int i=1;i<=n;++i)ans+=a[i];
		return !printf("%lld\n",ans);
	}
	for(int i=1;i<=min(l2,(n-1)/(d+1)+1);++i)
	{
		long long now=sum2[i];
		int tot=(i-1)*d;
		tot-=(l2-i);
		tot=max(tot,0);
		tot=min(l1,tot);
		now+=sum1[l1]-sum1[tot];
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}
