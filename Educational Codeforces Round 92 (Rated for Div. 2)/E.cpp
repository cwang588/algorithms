#include<cstdio>

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	int T,m,d,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&m,&d,&w);
		int g=gcd(d-1,w);
		int km,bm,kd,bd;
		long long ans=0;
		w/=g;
		m=min(m,d);d=min(m,d);
		km=m/w;bm=m%w;
		ans+=1ll*km*km*w;
		ans+=2ll*km*bm;
		ans+=bm;
		ans-=m;
		ans/=2;
		printf("%lld\n",ans);
	}
}
