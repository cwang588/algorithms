#include<bits/stdc++.h>
using namespace std;
char a[5005],b[5005];
int dp[5005][5005];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>(a+1)>>(b+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+2;
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])-1;
				dp[i][j]=max(0,dp[i][j]);
			}
			ans=max(dp[i][j],ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
