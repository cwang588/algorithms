#include<bits/stdc++.h>
using namespace std;
long long ys[35],ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		cin>>n;
		long long a=0,b=0;
		for(long long i=1;i<=n;++i)
		{
			long long tep;
			scanf("%lld",&tep);
			a+=tep;
		}
		for(long long i=1;i<=n;++i)
		{
			long long tep;
			scanf("%lld",&tep);
			b+=tep;
		}
		ans=a*b/n;
		long long re=(a*b)%n;
		for(int i=1;i<=31;++i)
		{
			re*=10;
			ys[i]=re/n;
			re%=n;
		}
		if(ys[31]>=5)
			++ys[30];
		for(int i=30;i>1;--i)
		{
			if(ys[i]==10)
			{
				ys[i-1]++;
				ys[i]=0;
			}
			else
				break;
		}
		if(ys[1]==10)
		{
			ys[1]=0;
			++ans;	
		}
		printf("%lld.",ans);
		for(int i=1;i<=30;++i)
			printf("%lld",ys[i]); 
		printf("\n");
	}
	return 0;
}
