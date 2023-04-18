#include<bits/stdc++.h>
using namespace std;
int a[105];
bool dp[105][20005],ky[20005];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(dp,false,sizeof(dp));
		memset(ky,false,sizeof(ky));
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;++i)
			dp[i][0]=true;
		for(int i=0;i<n;++i)
			for(int j=0;j<=10000;++j)
			{
				if(dp[i][j])
				{
					dp[i+1][j]=true;
					dp[i+1][abs(j-a[i+1])]=true;
					ky[abs(j-a[i+1])]=true;
					dp[i+1][j+a[i+1]]=true;
					ky[j+a[i+1]]=true;
				}
			}
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int t;
			scanf("%d",&t);
			if(t>10000)
			{
				printf("NO\n");
				continue;
			}
			if(ky[t])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
