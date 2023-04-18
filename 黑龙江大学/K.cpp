#include<bits/stdc++.h>
using namespace std;
long long s(long long x)
{
	long long tot=0;
	while(x)
	{
		tot+=x%10;
		x/=10;
	}
	return tot;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		cin>>n;
		if(n<=10)
		{
			cout<<n;
			continue;
		}
		long long a=9,b;
		while(a<=n)
		{
			a=a*10+9;
			if(a>n)
			{
				a=(a-9)/10;
				b=n-a;
				break;
			}
		}
		printf("%lld",s(a)+s(b));
		printf("\n");
	}
	return 0;
}
