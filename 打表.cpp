#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
unsigned long long d[19];
unsigned long long mo(unsigned long long ans)
{
	ans-=(ans/1000000007)*1000000007;
	return ans;
}
unsigned long long suan(unsigned long long x)
{
	if(x<10)
		return (x*x+x)/2;
	int w=0,m=0;
	unsigned long long t=x;
	while(t)
	{
		++w;
		m=t%10;
		t/=10;
	}
	unsigned long long ans=mo(m*d[w-1])+mo(mo((m-1)*m/2)*pow(10,w-1))+suan(x-m*pow(10,w-1))+mo(mo(x-m*pow(10,w-1)+1)*m);
	ans-=(ans/1000000007)*1000000007;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=18;++i)
	{
		d[i]=45*i*pow(10,i-1);
		d[i]-=(d[i]/1000000007)*1000000007;
	}
	while(t--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		long long ans1=suan(l-1),ans2=suan(r);
		if(ans1<=ans2)
			printf("%lld\n",ans2-ans1);
		else
			printf("%lld\n",ans2-ans1+mod); 
	}
	return 0;
}
