#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005],len[2005][2005];
char s[2005],t[2005];
int main(){
	while(cin>>(s+1)>>(t+1)){
		int n=strlen(s+1),m=strlen(t+1);
		for(int i=1;i<=n+1;++i)
			for(int j=1;j<=m+1;++j)
				dp[i][j]=len[i][j]=0;
		int ans=0;
		for(int i=n;i>=1;--i)
			for(int j=m;j>=1;--j){
				if(s[i]<t[j])len[i][j]=n-i+1+m-j+1;
				else len[i][j]=max(len[i+1][j],len[i][j+1]);
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j){
				ans=max(ans,dp[i][j]*2+len[i+1][j+1]);
				ans=max(ans,dp[i][j]*2+m-j);
			}
		printf("%d\n",ans);
	}
	return 0;
} 
