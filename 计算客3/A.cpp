#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,M;
int a[105],dp[105];
int main()
{
	int n;
	scanf("%d",&n); 
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		dp[i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(a[j]<a[i])
				dp[i]=max(dp[i],dp[j]+1);
	int ans=0,cnt=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[i]);
	for(int k=1;k<=n;++k)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
			dp[i]=1;
		dp[k]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
			{
				if(j==k||i==k)
					continue;
				if(a[j]<a[i])
					dp[i]=max(dp[i],dp[j]+1);
			}
		int t=0;
		for(int i=1;i<=n;++i)
			t=max(t,dp[i]);
		if(t<ans)
			++cnt;
	}
	printf("%d",cnt);
	return 0;
}
