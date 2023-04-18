#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
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
long long C[505][505],mi[505];
void init()
{
	mi[0]=1;
	for(int i=0;i<=500;++i)C[i][0]=1;
	for(int i=1;i<=500;++i)mi[i]=mi[i-1]*49%mod;
	for(int i=1;i<=500;++i)
		for(int j=1;j<=500;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	init();
	long long num=0,ans=mi[n];
	for(int i=1;i<=q;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==b&&b==c)++num;
		else if(a==b||b==c||a==c)num+=3;
		else num+=6; 
	}
	long long now=-1;
	for(int i=1;i<=n/3;++i)
	{
		ans=(ans+now*C[n-2*i][i]*quickpower(num,i,mod)*mi[n-3*i])%mod;
		now*=-1;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
