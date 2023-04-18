#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[1000005];
int main()
{
	int n;
	a[0]=1;
	a[1]=3;
	a[2]=22;
	a[3]=131;
	a[4]=823;
	a[5]=5096;
	scanf("%d",&n);
	for(int i=6;i<=n;++i)
	{
		a[i]=(4*a[i-1]%mod+14*a[i-2]%mod-10*a[i-4]%mod+a[i-6]%mod)%mod;
		while(a[i]<0)
			a[i]+=mod;
	}
	printf("%lld",a[n]);
	return 0;
}
