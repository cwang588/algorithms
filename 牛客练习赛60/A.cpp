#include<bits/stdc++.h>
using namespace std;
long long mi[35],num[35];
int main()
{
	int n;
	scanf("%d",&n);
	mi[0]=1;
	for(int i=1;i<=28;++i)mi[i]=mi[i-1]*2;
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		for(int j=0;j<=28;++j)if(mi[j]&t)++num[j];
	}
	long long ans=0;
	for(int i=0;i<=28;++i)ans+=mi[i]*num[i]*num[i];
	printf("%lld\n",ans);
	return 0;
}
