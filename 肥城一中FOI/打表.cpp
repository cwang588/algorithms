#include<bits/stdc++.h>
using namespace std;
const long long mod=1e8+7;
long long a[305];
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
	freopen("db.txt","w",stdout);9
	a[300]=1;
	for(int i=1;i<=300;++i)
		a[300]=a[300]*i%mod;
	a[300]=quickpower(a[300],mod-2,mod);
	for(int i=299;i>=1;--i)
		a[i]=a[i+1]*(i+1)%mod;
	cout<<"int db[]={0,"<<endl;
	for(int i=1;i<=300;++i)
		cout<<a[i]<<',';
	cout<<endl<<"};";
	return 0;
}
