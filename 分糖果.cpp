#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[105][105];
int dfs(int i,int j)
{
	if(dp[i][j])
		return dp[i][j];
	if(i<j)
		dp[i][j]=dfs(i,i);
	else if(i==j)
		dp[i][j]=dfs(i,j-1)+1;
	else
		dp[i][j]=dfs(i-j,j)+dfs(i,j-1);
	return dp[i][j];
}
int main()
{
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		memset(dp,0,sizeof(dp));
		dp[0][1]=dp[1][1]=1;
		int n=0,m=0;
		int i=0;
		while(line[i]!=',')
		{
			m=m*10+line[i]-'0';
			++i;
		}
		++i;
		while(i<strlen(line))
		{
			n=n*10+line[i]-'0';
			++i;			
		}
		printf("%d\n",dfs(m,n));
    }
    
    return 0;
} 
