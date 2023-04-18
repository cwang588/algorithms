//¿ìËÙÃİ 
#include<cstdio>
#include<iostream>
using namespace std;
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
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
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<quickpower(b,p,k);
	return 0;
}
