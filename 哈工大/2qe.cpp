#include<bits/stdc++.h>
using namespace std;
long long f1(long long n,double k)
{
	return (n-2*k)*((n-2*k)*(n-2*k)-3*n+2);
}
int main()
{
	int t;
	scanf("%d",&t);	
	while(t--)
	{
		long long n;
		cin>>n;
		double t=sqrt(3*n-2);
		double p=(n-sqrt(3.0)*t/3.0)/2;
		printf("%lld %lld\n",max(f1(n,p),f1(n,p+1)),min((n-p)/2+1,ceil(n/2)+1));
	}
	return 0;
}
