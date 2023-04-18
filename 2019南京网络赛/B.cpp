#include<bits/stdc++.h>
using namespace std;
long long Mod;
long long eular(long long n)
{
	long long ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
long long quickpower(long long a,long long b,long long p)
{
	a%=p;
	b%=p;
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
long long query(long long a,long long re,long long mod)
{
	if(mod==1)
		return 0;
	if(re==1)
		return a%mod;
	long long now=eular(mod);
	if(a>=8)
	{
		if(re>2)
			return quickpower(a,query(a,re-1,now)+now,Mod)%Mod;
		else
			return quickpower(a,a,Mod)%Mod;
	}
	else if(a>=3)
	{
		if(re>3)
			return quickpower(a,query(a,re-1,now)+now,Mod)%Mod;
		else if(re==3)
			return quickpower(a,quickpower(a,a,now),Mod)%Mod;
		else
			return quickpower(a,a,Mod)%Mod;
	}
	else 
	{
		if(re>4)
			return quickpower(a,query(a,re-1,now)+now,Mod)%Mod;
		if(re==4)
			return quickpower(a,16,Mod)%Mod;
		if(re==3)
			return quickpower(a,4,Mod)%Mod;
		if(re==2)
			return quickpower(a,2,Mod)%Mod;
	}
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	long long a,k;
	while(t--)
	{
		cin>>a>>k>>Mod;
		if(a==1)
		{
			printf("%lld",(long long)1%Mod);
			if(t!=1)
				printf("\n");
			continue;
		}
		if(k==0)
			printf("1");
		else
			printf("%lld",query(a,k,Mod)%Mod);
		if(t!=1)
			printf("\n");
	}
	return 0;
}
