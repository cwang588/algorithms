#include<bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define N 5005000
using namespace std;
typedef pair<long long,bool> data;
long long m,n,a;
long long prime[N+5],phi[N+5],cnt;
bool vis[N+5];
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
data ksm(long long w,long long b,long long MOD)
{
    long long s=1;
	bool fl=true;
    while (b)
	{
        if(b&1){if((s*=w)>=MOD)fl=false;s%=MOD;}
        b>>=1;if(b){if((w*=w)>=MOD)fl=false;w%=MOD;}
    }
    return mp(s,fl);
}
data Solve(long long st,long long MOD)
{
    if(MOD==1)return mp(0,false);
	if (st==n)return mp(a%MOD,a<MOD);
    data b=Solve(st+1,phi[MOD]);if (gcd(a,MOD)==1) return ksm(a,b.fr,MOD);
    if(!b.sc)b.fr+=phi[MOD];return ksm(a,b.fr,MOD);
}
int main()
{
	int t;
    scanf("%d",&t);
    phi[1]=1;
    for(long long i=2;i<=N;i++)
	{
        if(!vis[i])
            prime[++cnt]=i,phi[i]=i-1;
        for(long long j=1;j<=cnt&&prime[j]*i<=N;j++)
		{
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
			{
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    while(t--)
	{
    	cin>>a>>n>>m;
    	if(n==0)printf("%lld",1%m);
		else printf("%lld",Solve(1,m).first);
		if(t!=0)printf("\n");
	}
    return 0;
}

