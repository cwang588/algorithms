#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum1[40005],sum2[40005];
int a[40005],b[40005];
int main()
{	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	int last=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==1)
		{
			if(!last)last=i;
			else;
		}
		else
		{
			if(last)
			{
				int len=i-last;
				++sum1[len];
				last=0;
			}
		}
	}
	if(last)
	{
		int len=n+1-last;
		++sum1[len];
		last=0;
	}
	for(int i=1;i<=m;++i)
	{
		if(b[i]==1)
		{
			if(!last)last=i;
			else;
		}
		else
		{
			if(last)
			{
				int len=i-last;
				++sum2[len];
				last=0;
			}
		}
	}	
	if(last)
	{
		int len=m+1-last;
		++sum2[len];
		last=0;
	}
	long long ans=0;	
	for(int i=1;i*i<=k;++i)
	{
		if(k%i==0)
		{
			int tmp=k/i;
			long long num1=0,num2=0,num3=0,num4=0;
			for(int j=tmp;j<=n;++j)num1+=(long long)sum1[j]*(j-tmp+1);
			for(int j=tmp;j<=m;++j)num2+=(long long)sum2[j]*(j-tmp+1);
			if(num1>0)
			{
				for(int j=i;j<=m;++j)
					num3+=(long long)sum2[j]*(j-i+1);
			}
			if(num2>0)
			{
				for(int j=i;j<=n;++j)
					num4+=(long long)sum1[j]*(j-i+1);
			}
			ans+=num1*num3;
			if(i!=tmp)ans+=num2*num4;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
