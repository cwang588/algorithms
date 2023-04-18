#include<cstdio>
#include<algorithm>
using namespace std;
int fg[55][55];
int dp[55][55][55][55];
int main()
{
//	freopen("10.in","r",stdin);
//	freopen("10.out","w",stdout);
	int n;
	scanf("%d",&n);	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	fg[a][b]=c;
	while(a||b||c)
	{
		scanf("%d%d%d",&a,&b,&c);
		fg[a][b]=c;
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
					dp[i][j][k][l]+=(fg[i][j]+fg[k][l]);
					if(i==k&&j==l)
						dp[i][j][k][l]-=fg[i][j]; 
				}
	printf("%d",dp[n][n][n][n]);
	return 0;
}
