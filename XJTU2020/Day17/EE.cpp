#include<bits/stdc++.h>
using namespace std;
unsigned long long fac[25];
int nn;
int a[1005],tmp[1005];
struct number
{
	int num[15],ans[15];
}N[25][400005];
bool cmp(number x,number y)
{
	for(int i=1;i<nn;++i)if(x.num[i]!=y.num[i])return x.num[i]<y.num[i];
	return false;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=19;++i)fac[i]=fac[i-1]*i;
}
bool usd[52];
void dfs(int n,int now,long long re)
{
	if(now==n)
	{
		for(int i=1;i<=n;++i)if(!usd[i])printf("%d\n",i);
		return;
	}
	long long tmpp=0;
	for(int i=1;i<=n;++i)
	{
		if(!usd[i])
		{
			tmpp+=fac[n-now];
			if(re<=tmpp)
			{
				printf("%d ",i);
				usd[i]=true;
				dfs(n,now+1,re+fac[n-now]-tmpp);
				return;
			}
		}
	}
}
int main()
{
	init();
	for(int i=2;i<=9;++i)
	{
		nn=i;
		int now=0;
		for(int j=1;j<=i;++j)a[j]=j;
		for(int j=1;j<i;++j)tmp[j]=a[j+1]-a[j];
		++now;
		for(int j=1;j<i;++j)N[i][now].num[j]=tmp[j];
		for(int j=1;j<=i;++j)N[i][now].ans[j]=a[j];
		while(next_permutation(a+1,a+1+i))
		{
			for(int j=1;j<i;++j)tmp[j]=a[j+1]-a[j];
			++now;
			for(int j=1;j<i;++j)N[i][now].num[j]=tmp[j];
			for(int j=1;j<=i;++j)N[i][now].ans[j]=a[j];
		}
		sort(N[i]+1,N[i]+1+now,cmp);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n<=9)
		{
			for(int i=1;i<=n;++i)
			{
				printf("%d",N[n][k].ans[i]);
				if(i!=n)printf(" ");
			}
			printf("\n");
		}
		else
		{
			for(int i=1;i<=20;++i)usd[i]=false;
			usd[1]=usd[n]=true;
			printf("%d 1 ",n);
			dfs(n,3,k);
		}
	}
	
	return 0;
}
