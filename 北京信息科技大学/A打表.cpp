#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("db.cpp","w",stdout);
//	int t;
//	scanf("%d",&t);
	cout<<"int db[]={0,";
	long long n=0;
	while(++n&&n<=100000)
	{
//		scanf("%lld",&n);
		long long a=1,b=1,ans=0,num=n;
		while(num%2==0)
		{
			a*=2;
			b*=2;
			num/=2;
		}
		if(!num)
		{
			printf("0\n");
			continue;
		}
		a*=2;
		num=num/2+1;
		while(num>1&&b<n)
		{
			if(num%2==0)
			{
				ans+=abs(a-b);
				b+=a;
				if(num-2>=2)
					a*=2;
				num/=2;
			}
			else
			{
				if(a>b)
				{
					ans+=b+abs(a-b);
					b+=2*a;
					if(num-3>=2)
						a*=2;
					num/=2;
				}
				else
				{
					a*=2;
					num=num/2+1;
				}
			}
		}
		printf("%lld,",ans);
		if(n%10==0)
			cout<<endl;
	}
	return 0;
}
