#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
inline long long read() 
{    
	long long tmp=0,fh=1;
	char c=getchar();
	while (c<'0'||c>'9') 
	{
		if(c=='-') 
			fh=-1; 
		c=getchar();
	}   
	while(c>='0'&&c<='9')tmp=tmp*10+c-48,c=getchar();
	return tmp*fh;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n=read(),m=read();
		if(n==1)
		{
			printf("Yes\n");
			continue;
		}
		if(m<n)
		{
			if(2*m<n)
			{
				printf("Yes\n");
				continue;
			}
			else if(2*m==n)
			{
				printf("No\n");
				continue;
			}
			else
			{
				long long g=gcd(n,m);
				long long nn=n/g,mm=m/g;
				if(nn==mm+1)printf("No\n");
				else printf("Yes\n");
				continue;
			}
		}
		else if(m==n)
		{
			printf("Yes\n");
			continue;
		}
		else
		{
			if(m%n==0)printf("Yes\n");
			else printf("No\n");
		}
	}	
	return 0;
}
