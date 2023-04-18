#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	long long l=2,r=2;
	for(int i=n;i>=1;--i)
	{
		l=(l-1)/a[i]+1,r=r/a[i];
		if(l>r)return !printf("-1\n");
		l*=a[i];
		r=r*a[i]+a[i]-1;
	}
	printf("%lld %lld\n",l,r);
	return 0;
}
