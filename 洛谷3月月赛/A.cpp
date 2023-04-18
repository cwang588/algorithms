#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char shu[50000005];
unsigned long long x=9223372036854775808;
int main()
{
	long long l,r,t;
	scanf("%lld%lld%lld",&l,&r,&t);
	for(int i=1;i<=t;++i)
	{
		memset(shu,' ',sizeof(shu));
		scanf("%s",&shu);
		unsigned long long num;
		int ll=strlen(shu);
		if(shu[0]=='-')
		{
			if(shu[1]=='0')
			{
				printf("1\n");
				continue;
			}
			else
			{
				num=0;
				if(ll-1>19)
				{
					printf("2\n");
					continue;	
				}
				for(int j=1;j<ll;++j)
					num=num*10+shu[j]-'0';
				if(num>=x)
				{
					printf("2\n");
					continue;	
				}	
				long long nnum=(long long)num;
				nnum*=-1;
				if(nnum>r||nnum<l)
				{
					printf("2\n");
					continue;
				}
				else
				{
					printf("0\n");
					continue;
				}
			}
		}
		else
		{
			if(shu[0]=='0')
			{
				if(shu[1]>='0'&&shu[1]<='9')
				{
					printf("1\n");
					continue;
				}
				else
				{
					if(0<l||0>r)
					{
						printf("2\n");
						continue;
					}
					else
					{
						printf("0\n");
					}
				}
			}
			else
			{
				num=0;
				if(ll>19)
				{
					printf("2\n");
					continue;	
				}
				for(int j=0;j<ll;++j)
					num=num*10+shu[j]-'0';
				if(num>=x)
				{
					printf("2\n");
					continue;	
				}	
				long long nnum=(long long)num;
				if(nnum<=r&&nnum>=l)
				{
					printf("0\n");
					continue;
				}
				else
				{
					printf("2\n");
					continue;
				}				
			}
		}
	}
	return 0;
}
