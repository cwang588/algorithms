#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long Max=0,Min=100000000000000000;
	for(int i=1;i<=n;++i)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long now=y*(x-y)*(x-y);
		Min=min(Min,now);
		Max=max(Max,now);
	}
	printf("%lld\n",Max-Min);
	return 0;
}
