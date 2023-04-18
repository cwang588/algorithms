#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a<b||d<b)printf("No\n");
		else if(c>=b)printf("Yes\n");
		else
		{
			long long l=a-b,r=a-c-1;
			long long t=gcd(b,d);
			if(l/t==r/t)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
