#include<bits/stdc++.h>
using namespace std;
int a[25][25],dp[25][25][25][25];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l)
				{
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]);
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k-1][l]);
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]);
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l-1]);
					dp[i][j][k][l]+=(a[i][j]+a[k][l]);
					if(i==k&&j==l)
						dp[i][j][k][l]-=a[i][j]; 
				}
	printf("%d",dp[n][n][n][n]);
	return 0;
}
