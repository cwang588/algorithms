#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;	
	scanf("%lld",&n);
	long long ans,tmp=1000000000002;
	for(long long i=1;i<=1000000;++i)
	{
		if(abs(i*i-n)<tmp)
		{
			ans=i*i;
			tmp=abs(i*i-n);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
