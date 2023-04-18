#include<bits/stdc++.h>
using namespace std;
int a[505];
int dp[505][505];
int Min[505][505];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int l=i,r=i+j-1;
			if(r>n)break;
			int ans=r-l+1;
			for(int k=l;k<=r;++k)
			
			Min[l][r]=ans;
		}
	}
	for(int len=1;len<=n;++len)
		for(int l=1;l<=n;++l)
		{
			int r=l+len-1;
			if(r>n)break;
			dp[l][r]=Min[l][r];
			for(int k=l;k<r;++k)dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
		}
	printf("%d\n",dp[1][n]);
	return 0;
}
