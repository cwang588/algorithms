#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int fj[25];
long long sz(long long x)
{
	memset(fj,0,sizeof(fj));
	long long ret=0;
	for(int i=14;i>=0;--i)
	{
		long long t=pow(16,i);
		if(x>=t)
		{
			fj[i]=x/t;
			x-=fj[i]*t;
			ret+=fj[i];
		}
	}
	return ret%15;
}
long long cl(long long x)
{
	long long ret=0;
	long long t=x%15;
	for(long long i=x;i>=x-t+1;--i)
		ret+=sz(i);
	return ret%15;
}
int main()
{
	long long l,r;
	cin>>l>>r;
	long long ans=cl(r)-cl(l-1);
	while(ans<0)
		ans+=15;
	cout<<ans%15;
	return 0;
}
