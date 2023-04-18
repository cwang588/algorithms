#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long mo[10000005];
void init()
{
	mo[1]=1;
	for(int i=2;i<=10000000;++i)
		mo[i]=mo[i-1]*i%mod;
}
long long mi(long long a,long long b,long long p)
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
	int t; 
	scanf("%d",&t);
	init();
	while(t--)
	{
		long long n;
		cin>>n;	
		long long t=(n+1)*(n+1)%mod*n%mod*n%mod*748683265%mod;
		cout<<t<<' '<<mi(mo[n],2*n,mod)<<endl;		
	}
	return 0;
}
