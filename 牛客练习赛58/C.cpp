#include<bits/stdc++.h>
using namespace std;
long long a[25][25];
long long sum1[25],sum2[25];
bool usd[25];
long long t[25];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%lld",&a[i][j]);
			sum1[i]+=a[i][j];
			sum2[j]+=a[i][j];
		}
	int Max=(1<<(n))-1;
	long long tot=0;
	for(int i=0;i<=Max;++i)
	{
		int num=0;
		long long ans=0;
		for(int j=1;j<=20;++j)usd[j]=false,t[j]=0;
		for(int j=0;(1<<j)<=i;++j)
		{
			if((1<<j)&i)
			{
				usd[j+1]=true;
				ans+=sum1[j+1];
				++num;
			}
		}
		if(num>k)continue;
		for(int j=1;j<=m;++j)
		{
			t[j]=sum2[j];
			for(int k=1;k<=n;++k)
				if(usd[k])
					t[j]-=a[k][j];
		}
		sort(t+1,t+1+m,cmp);
		for(int j=1;j<=k-num;++j)ans+=t[j];
		tot=max(tot,ans);
	}
	printf("%lld\n",tot);
	return 0;
}
