#include<cstdio>
#include<iostream>
using namespace std;
unsigned long long quickpower(unsigned long long a,unsigned long long b,unsigned long long p)
{
	unsigned long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int main()
{
	long long b,p,k;
//	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<quickpower(24,1000000005,1000000007);
	return 0;
}
