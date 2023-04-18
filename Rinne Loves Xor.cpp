#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[100005],b[100005],c[100005];
long long mi[100005];
long long numa[100005][35],numb[100005][35];
void Init(int n)
{
	mi[0]=1;
	for(int i=1;mi[i-1]<=1000000000;++i)mi[i]=mi[i-1]*2;
	for(int i=1;i<=n;++i)
	{
		long long tmp=1;
		int now=0;
		while(tmp<=a[i])
		{
			if(tmp&a[i])numa[i][now]=numa[i-1][now]+1;
			else numa[i][now]=numa[i-1][now];
			++now;
			tmp<<=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		long long tmp=1;
		int now=0;
		while(tmp<=b[i])
		{
			if(tmp&b[i])numb[i][now]=numb[i-1][now]+1;
			else numb[i][now]=numb[i-1][now];
			++now;
			tmp<<=1;
		}
	}	
}
void work(int i)
{
	int now=0;
	long long tmp=1;
	while(tmp<=1000000000)
	{
		if(tmp&a[i])c[i]=(c[i]+mi[now]*(i-1-numb[i-1][now])%mod)%mod;
		else c[i]=(c[i]+mi[now]*numb[i-1][now]%mod)%mod;			
		++now;
		tmp<<=1;
	}
	now=0;
	tmp=1;
	while(tmp<=1000000000)
	{
		if(tmp&b[i])c[i]=(c[i]+mi[now]*(i-1-numa[i-1][now])%mod)%mod;
		else c[i]=(c[i]+mi[now]*numa[i-1][now]%mod)%mod;			
		++now;
		tmp<<=1;
	}	
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
	Init(n);
	for(int i=1;i<=n;++i)
	{
		c[i]=c[i-1];
		c[i]=(c[i]+a[i]^b[i])%mod;
		work(i);
		printf("%lld ",c[i]);
	}
	return 0;
}
