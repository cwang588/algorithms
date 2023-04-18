#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 19260817
int mul(int x,int y)
{
    ll z=1ll*x*y;
    return z-z/mod*mod;
}
int add(int x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int n,k,inv[22],C[44][44],dp[44][22][44];
char a[44],b[44];
void init()
{
    inv[1]=1;
    for(int i=2;i<=20;i++)inv[i]=mul(mod-mod/i,inv[mod%i]);
    for(int i=0;i<=40;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
    }
    for(int n=1;n<=40;n++)
    {
        dp[n][0][0]=1;
        for(int i=1;i<=min(20,C[n][3]);i++)
            for(int j=0;j<=n;j++)
            {
                if(j+1<=n)dp[n][i][j]=add(dp[n][i][j],mul(dp[n][i-1][j+1],mul(C[j][1],C[n-j][2])));
                if(j+3<=n)dp[n][i][j]=add(dp[n][i][j],mul(dp[n][i-1][j+3],C[n-j][3]));
                if(j>=1)dp[n][i][j]=add(dp[n][i][j],mul(dp[n][i-1][j-1],mul(C[j][2],C[n-j][1])));
                if(j>=3)dp[n][i][j]=add(dp[n][i][j],mul(dp[n][i-1][j-3],C[j][3]));
                if(i>=2)dp[n][i][j]=add(dp[n][i][j],mod-mul(dp[n][i-2][j],add(C[n][3],mod-(i-2))));
                dp[n][i][j]=mul(dp[n][i][j],inv[i]);
            }
    }
}
int main()
{
    int Case=1;
    init();
	for(n=1;n<=40;++i)
		for(k=1;k<=min(20,(n*(n-1)*(n-2)/6));++k)
		{
	        int m=0;
	        for(int i=0;i<n;i++)m+=(a[i]-'0')^(b[i]-'0');
	        printf("%d\n",dp[n][k][m]);
    	}
	return 0;
}
