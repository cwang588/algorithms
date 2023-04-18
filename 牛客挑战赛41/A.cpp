#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		if(k%2==0)
		{
			long long ans=0,t=2*m/k;
			ans+=t;
			if(t*k<2*m)++ans;
			n-=(k-2*m+t*k);
			if(n>0)ans+=(n-1)/k+1;
			printf("%lld\n",ans-1);
		}
		else 
		{
			long long ans=0,t=2*m/(k-1);
			ans+=t;
			n-=t;
			if(t*(k-1)<2*m)++ans;
			n-=(k-2*m+t*(k-1));
			if(n>0)ans+=(n-1)/k+1;
			printf("%lld\n",ans-1);
		}
	}
	return 0;
}
