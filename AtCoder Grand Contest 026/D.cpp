#include<bits/stdc++.h>
using namespace std;
const long long &mod=1000000007;
long long h[105];
long long mi[1005],inv[1005];
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
long long solve(int l,int r,long long hh,long long lastlen,long long lastky,long long lastbky)
{
	long long nowlen=(long long)(r-l+1);
	if(l==r)return quickpower(2,h[l]-hh,mod)%mod;
	if(l>r)return 0;
	long long Min=2147483647,re=0;
	for(int i=l;i<=r;++i)Min=min(Min,h[i]-hh);
	long long ky=0,bky=0,ansky=0,ansbky=0;
	if(hh>0)
	{
		ky=(lastbky*quickpower((mi[lastlen]-2+mod)%mod,mod-2,mod)%mod*(mi[lastlen-nowlen+1]-2)%mod+lastky)%mod;
		ansbky=bky=((lastbky+lastky-ky)%mod+mod)%mod;
		ansky=ky*mi[Min]%mod;
	}
	else
	{
		ansbky=(mi[nowlen]-2)%mod;
		ansky=mi[Min]%mod;
	}
	re=(ansky+ansbky)%mod;
	int last=0;
	long long tmp=0;
	for(int i=l;i<=r;++i)
	{
		if(h[i]-hh==Min)
		{
			if(last!=-1)
			{
				tmp=(tmp+solve(last+1,i-1,hh+Min,nowlen,ansky,ansbky))%mod;
				last=-1;
			}
			else last=i;
		}
	}
	if(last!=-1)tmp=(tmp+solve(last+1,r,hh+Min,nowlen,ansky,ansbky))%mod;
	if(!tmp)tmp=1;
	return re*tmp%mod;
}
void init()
{
	mi[0]=1;
	for(int i=1;i<=150;++i)mi[i]=mi[i-1]*2%mod;
	inv[150]=quickpower(mi[150],mod-2,mod);
	for(int i=149;i>=0;--i)inv[i]=inv[i+1]*2%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i)scanf("%lld",&h[i]);
	long long ans=solve(1,n,0,n,0,0);
	printf("%lld\n",ans);
	return 0;
}
