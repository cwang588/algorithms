#include<bits/stdc++.h>
using namespace std;
int a[70],tong[3500],n;
bool usd[70];
bool cmp(int x,int y)
{
	return x>y;
}
bool dfs(int num,int now)
{
	if(num==n+1)
		return true;
	
}
int main()
{
	scanf("%d",&n);
	int tot=0,sum=0,Max=0;
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(t<=50)
		{
			sum+=t;
			a[++tot]=t;
			Max=max(Max,t);
			++tong[t];
		}
	}
	sort(a+1,a+1+tot,cmp);
	n=tot;
	int ans=sum;
	for(int i=2;i*i<=sum;++i)
	{
		if(sum%i==0)
		{
			if(i>=Max&&dfs(i,1))
				return !printf("%d",i);
			if(dfs(sum/i,1))
				ans=sum/i;
		}
	}
	printf("%d",ans);
	return 0;
}
