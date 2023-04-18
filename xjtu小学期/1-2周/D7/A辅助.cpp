#include<cstdio>
#include<iostream>
using namespace std;
unsigned long long quickpower(unsigned long long a,unsigned long long b)
{
	unsigned long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=ans*base;
		base=base*base;
		b>>=1;
	}
	return ans;
}
int main()
{
	unsigned long long b,p;
	cin>>b>>p;
	cout<<b<<"^"<<p<<"="<<quickpower(b,p);
	return 0;
}
