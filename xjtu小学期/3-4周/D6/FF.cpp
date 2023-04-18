#include<bits/stdc++.h>
using namespace std;
int dp[200005][20],Max[200005][20],Min[200005][20];
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=200005;++i)
		for(int j=1;j<20;++j)
			Min[i][j]=2147483647;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&Min[i][0]);
		Max[i][0]=Min[i][0];
	}
	for(int j=1;j<=20;++j)
		for(int i=1;i<=m;++i)
			if(i+(1<<j)-1<=m)
			{
				Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
				Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]); 
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
				dp[i][j]=max(dp[i][j],Max[i+(1<<(j-1))][j-1]-Min[i][j-1]);
			}
	for(int i=1;i<=n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
 		int k=0;
   		while(1<<(k+1)<=r-l+1)
       		k++;
		int ans=max(dp[l][k],dp[r-(1<<k)+1][k]);
		ans=max(ans,Max[r-(1<<k)+1][k]-Min[l][k]);
		printf("%d\n",ans);
	}
	return 0;
}
