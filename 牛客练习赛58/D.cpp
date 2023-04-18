#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char s[1005][1005];
int dp[1005][1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=s[1][1]=='1';
	for(int num=1;num<=100;++num)
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			if(s[i][j]=='1') continue;
			if(s[i][j-1]=='0') dp[i][j]=min(dp[i][j],dp[i][j-1]);
			if(s[i][j-1]=='0'&&s[i+1][j-1]=='0') dp[i][j]=min(dp[i][j],dp[i+1][j-1]+(s[i+1][j]=='0')+(s[i+2][j-1]=='0'));
			if(s[i-1][j]=='0') dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i-1][j+1]=='0'));
		}
	if(dp[n][m]>n*m) printf("-1\n");
	else printf("%d\n",dp[n][m]);
}

