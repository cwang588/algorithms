#include<bits/stdc++.h>
using namespace std;
int C[15],K[15],P[15],price[1005],num[1005][15],dp[15][15][15][15][15];
int main()
{
	int b,s;
	scanf("%d",&b);
	for(int i=1;i<=b;++i)scanf("%d%d%d",&C[i],&K[i],&P[i]);
	for(int i=0;i<=5;++i)
		for(int j=0;j<=5;++j)
			for(int k=0;k<=5;++k)
				for(int x=0;x<=5;++x)
					for(int y=0;y<=5;++y)
						dp[i][j][k][x][y]=P[1]*i+P[2]*j+P[3]*k+P[4]*x+P[5]*y;
	scanf("%d",&s);
	for(int i=1;i<=s;++i)
	{
		int sum;
		scanf("%d",&sum);
		for(int j=1;j<=sum;++j)
		{
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			num[s][xx]=yy;
		}
		scanf("%d",&price[i]);
	}
	for(int now=1;now<=s;++now)
		for(int i=0;i<=5;++i)
			for(int j=0;j<=5;++j)
				for(int k=0;k<=5;++k)
					for(int x=0;x<=5;++x)
						for(int y=0;y<=5;++y)
							if(i>=num[now][C[1]]&&j>=num[now][C[2]]&&k>=num[now][C[3]]&&x>=num[now][C[4]]&&y>=num[now][C[5]])
								dp[i][j][k][x][y]=min(dp[i][j][k][x][y],price[now]+dp[i-num[now][C[1]]][j-num[now][C[2]]][k-num[now][C[3]]][x-num[now][C[4]]][y-num[now][C[5]]]);
	printf("%d\n",dp[K[1]][K[2]][K[3]][K[4]][K[5]]);
	return 0;
} 
