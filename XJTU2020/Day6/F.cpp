#include<bits/stdc++.h>
using namespace std;
bool usd[2005][2005];
const long long mod=1000000007;
long long dp[4005][3205];
int mi[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
int main()
{
	int n,m,p; 
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		usd[x][y]=true;
	}
	int tmp=0;
	for(int i=2*m;i>=m;--i)tmp+=mi[i];
	dp[0][tmp]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<mi[2*m+1];++j)
		{
			for(int k=0;k<=2*m;++k)
			{
				if(j&mi[k])
				{
					int now=i+m-k;
					if(now>0&&now<=n&&!usd[i][now])dp[i][j]=(dp[i][j]+dp[i-1][((j-mi[k])>>1)+mi[2*m]])%mod;
				}
			}
		}
	printf("%d\n",dp[n][tmp]);
	return 0;
}
