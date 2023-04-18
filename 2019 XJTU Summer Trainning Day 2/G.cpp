#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[2005][2005],L[2005];
struct qj
{
	int l,r;
}q[2005];
int main()
{
	int t;
	scanf("%d",&t);
	for(int now=1;now<=t;++now)
	{
		memset(dp,0,sizeof(dp));
		memset(L,0,sizeof(L));		
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&q[i].l,&q[i].r);
			L[q[i].l-1]=max(L[q[i].l-1],q[i].r-q[i].l+1);
		}
		for(int i=1;i<=n;++i)
			L[i]=max(L[i],L[i-1]-1);
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=k;++j)
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
				dp[i+L[i]][j+1]=max(dp[i+L[i]][j+1],dp[i][j]+L[i]);				
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}
