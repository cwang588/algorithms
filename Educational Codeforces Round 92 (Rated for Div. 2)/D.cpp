#include<cstdio>

inline long long abs(long long x)
{
	return x>0?x:-x;
}
inline long long min(long long x,long long y)
{
	return x<y?x:y;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,k;
		long long l1,l2,r1,r2,a,b,c;
		scanf("%lld%lld",&n,&k);
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if((l1<=l2&&r2<=r1)||(l2<=l1&&r1<=r2))
			{a=0;b=abs(r2-l2-r1+l1),c=min(r2-l2,r1-l1);}
		else if((l1<=l2&&l2<=r1&&r1<=r2)||(l2<=l1&&l1<=r2&&r2<=r1))
		{
			a=0;
			b=(l1<=l2?r2-r1+l2-l1:r1-r2+l1-l2);
			c=(l1<=l2?r1-l2:r2-l1);
		}
		else 
		{
			a=(l1<=l2?l2-r1:l1-r2);
			b=(l1<=l2?r2-l1:r1-l2);
			c=0;
		}
		k-=n*c;
		if(k<=0)
		{
			printf("0\n");
		}
		else if(n*b>=k)
		{
			long long r=(k+b-1)/b;
			if(r==1)printf("%lld\n",a+k);
			else if(a>=k%b&&k%b!=0) printf("%lld\n",(r-1)*(a+b)+2*(k%b));
			else printf("%lld\n",r*a+k);
		}
		else
		{
			printf("%lld\n",n*a+n*b+2*(k-n*b));
		}
	}
}
