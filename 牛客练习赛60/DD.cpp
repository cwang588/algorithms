#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
void exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    long long x1,y1;
    exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
}	
long long Floor(long long x,long long y)
{
	if(x*y>=0)
	{
		x=x>=0?x:-x;
		y=y>=0?y:-y;
		return x/y;
	}
	else
	{
		x=x>=0?x:-x;
		y=y>=0?y:-y;
		if(x%y==0)return -x/y;
		else return -(x/y+1);
	}
}
bool judge(long long x,long long y,long long B,long long C,long long K)
{
	long long tmp=Floor(K*y,B);
	return C*tmp+K*x>=0;
}
int main()
{
	srand((unsigned)time(NULL));
	long long a,b,c,k;
//		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	bool ky=true;
	while(ky)
	{
		a=rand()*rand()%100000+1;
		b=rand()*rand()%100000+1;
		c=rand()*rand()%100000+1;
		k=rand()*rand()+1;		
		long long gcdd=gcd(b,c);
		for(long long i=0;i<=b;++i)
		{
			long long kk=k-a*i;
			if(kk%gcdd||kk<0)continue;
			long long B=b/gcdd,C=c/gcdd,K=kk/gcdd;
			long long x,y;
			exgcd(B,C,x,y);
			if(judge(x,y,B,C,K))
			{
				if(i*a+(x*K+C*Floor(K*y,B))*b+(y*K-B*Floor(K*y,B))*c!=k||(x*K+C*Floor(K*y,B))<0||(y*K-B*Floor(K*y,B))<0)
				{
					ky=false;
					printf("%lld %lld %lld %lld\n",a,b,c,k);
				}
				//else printf("Accepted!\n");
				break;
			}
			//	return printf("%lld %lld %lld\n",i,(x*K+C*Floor(K*y,B)),(y*K-B*Floor(K*y,B)));
		}
	}	
	return 0;
}
