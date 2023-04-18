#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,s;
	cin>>n>>m>>s;
	for(long long i=1;i<=m;++i)
		if(s%i+s/i<=n)
		{
			printf("YES\n");
			printf("0 0 %lld %lld %lld %lld",s%i,i,s%i+s/i,i-1);
			return 0;
		}
	for(long long i=1;i<=n;++i)
		if(s%i+s/i<=m)
		{
			printf("YES\n");
			printf("0 0 %lld %lld %lld %lld",i,s%i,i-1,s%i+s/i);
			return 0;
		}
	printf("NO");
	return 0;
}
