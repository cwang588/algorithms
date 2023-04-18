#include<bits/stdc++.h>
using namespace std;
int dp[1003][1003],a[1003];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)return !printf("YES\n");
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j)
		{
			if(dp[i-1][(j-a[i]+m)%m])
				dp[i][j]=1;
		}
	for(int i=1;i<=n;++i)
		if(dp[i][0])return !printf("YES\n");
	printf("NO\n");
	return 0;
}
