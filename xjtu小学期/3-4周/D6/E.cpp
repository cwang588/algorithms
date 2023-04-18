#include<bits/stdc++.h> 
using namespace std;
int dp[100005][20];
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		scanf("%d",&dp[i][0]);
	for(int j=1;j<=20;++j)
		for(int i=1;i<=m;++i)
			if(i+(1<<j)-1<=m)
				dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d ",min(dp[l][k],dp[r-(1<<k)+1][k]));
	}
	return 0;
}
