#include<cstdio>
#include<cmath>
#include<cstring>

typedef long long LL;
LL n,m,p;
LL power(LL a,LL b,LL p)
{
	LL ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
LL fac(LL n,LL p,LL pk)
{
	if(!n)
		return 1;
	LL ans=1;
	for(int i=1;i<pk;i++)
		if(i%p)
			ans=ans*i%pk;
	ans=power(ans,n/pk,pk);
	for(int i=1;i<=n%pk;i++)
		if(i%p)
			ans=ans*i%pk;
	return ans*fac(n/p,p,pk) % pk;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	LL xx,yy,ans=exgcd(b,a%b,xx,yy);
	x=yy;
	y=xx-a/b*yy;
	return ans;
}
LL inv(LL a,LL p)
{
	LL x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
LL C(LL n,LL m,LL p,LL pk)
{
	if(n<m) return 0;
	LL f1=fac(n,p,pk),f2=fac(m,p,pk),f3=fac(n-m,p,pk),cnt=0;
	for(LL i=n;i;i/=p)
		cnt += i / p;
	for(LL i=m; i; i/=p)
		cnt-=i/p;
	for(LL i=n-m;i;i/=p)
		cnt-=i/p;
	return f1*inv(f2,pk)%pk*inv(f3,pk)%pk*power(p,cnt,pk)%pk;
}
LL a[1000005],c[1000005];
int cnt;
LL CRT()
{
	LL M=1,ans=0;
	for(int i=0;i<cnt;i++)
		M*=c[i];
	for(int i=0;i<cnt;i++)
		ans=(ans+a[i]*(M/c[i])%M*inv(M/c[i],c[i])%M)%M;
	return ans;
}
LL exlucas(LL n,LL m,LL p)
{
	LL tmp=sqrt(p);
	for(int i=2;p>1&&i<=tmp;i++)
	{
		LL tmp=1;
		while(p%i==0)
			p/=i,tmp*=i;
		if(tmp>1)
			a[cnt]=C(n,m,i,tmp),c[cnt++]=tmp;
	}
	if(p>1) a[cnt]=C(n,m,p,p),c[cnt++]=p;
	return CRT();
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		scanf("%lld%lld%lld",&n,&m,&p);
		printf("%lld\n",exlucas(m+n,m,p));
	}
	return 0;
}
