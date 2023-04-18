#include<bits/stdc++.h>
using namespace std;
bool check(long long n,long long m,int tot)
{
	int tmp=0;
	long long now=m;
	while(now<=n)
	{
		tmp+=n/now;
		now*=m;
	}
	return tmp>=tot;
}
int work(int x,int cnt)
{
	int l=1,r=1e9;
	while(l<r-1)
	{
		int m=(r+l)>>1;
		if(check(m,x,cnt))r=m;
		else l=m; 
	}
	if(check(l,x,cnt))return l;
	return r;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,ans=0;
		scanf("%d",&n);
//		if(n==1)
//		{
//			printf("1\n");
//			continue;
//		}
		for(int i=2;i*i<=n;++i)
		{
			if(n%i==0)
			{
				int cnt=0;
				while(n%i==0)
				{
					n/=i;
					++cnt;
				}
				ans=max(ans,work(i,cnt));
			}
		}
		if(n)ans=max(ans,n);
		printf("%d\n",ans);
	}
	return 0;
} 
