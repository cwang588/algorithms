#include<cstdio>
#include<iostream>
using namespace std;
struct portal
{
	long long l,r;
}p[205];
long long cnt,tot;
void dfs(long long now,long long re)
{
	tot=now;
	if(re==1)
		return;
	if(re%2)
	{
		++cnt;
		p[cnt].l=now;
		p[cnt].r=199;
		dfs(now+2,re-1);
	}
	else
	{
		++cnt;
		p[cnt].l=now;
		p[cnt].r=now+2;
		++cnt;
		p[cnt].l=now+1;
		p[cnt].r=now ;
		dfs(now+3,re/2);
	}
}
void print()
{
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("%lld %lld\n",p[i].l,p[i].r);
	cnt=0;
	tot=0;
}
int main()
{
	long long n;
	while(cin>>n)
	{
		if(n==0)
		{
			printf("2\n1 1\n2 2\n");
			continue;
		}
		if(n==1)
		{
			printf("2\n1 199\n2 2\n");
			continue;
		}
		dfs(1,n);
		++cnt;
		p[cnt].l=tot-1;
		p[cnt].r=199;	
		print();
	}
	return 0;
}
