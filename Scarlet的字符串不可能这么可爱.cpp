#include<cstdio>
using namespace std;

long long Mode(long long a, long long b, long long mode)
{
	long long sum = 1;
	while (b) 
	{
		if (b & 1) 
		{
			sum = (sum * a) % mode;
			b--;
		}
		b /= 2;
		a = a * a % mode;
	}
	return sum;
}


int main()
{
	int k,l,p;
	scanf("%d%d%d",&k,&l,&p);
	int s,w;
	scanf("%d%d",&s,&w);
	long long ans=1;
	if(s<=2)
	{
		if(s==1)
			ans=k-1;
		else if(s==2)
			ans=k;
		else
			ans=k*(k-1)%p;
		ans=ans*Mode(k-2,l-2,p)%p;
	}
	else
	{
		ans=k*(k-1)%p;
		ans=ans*Mode(k-2,l-3,p)%p;
	}
	printf("%lld",ans);
	return 0;
}
