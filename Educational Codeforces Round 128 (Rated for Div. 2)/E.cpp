#include<bits/stdc++.h>
using namespace std;
char a[2][200005];
int dp[200005][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[0][i];
		for(int i=1;i<=n;++i)cin>>a[1][i];
		int l1=n+1,l2=n+1,r1=0,r2=0;
		for(int i=1;i<=n;++i){
			if(a[0][i]=='*'){
				l1=min(l1,i);
				r1=max(r1,i);
			}
			if(a[1][i]=='*'){
				l2=min(l2,i);
				r2=max(r2,i);
			}
		}
		if(a[0][min(l1,l2)]=='*'&&a[1][min(l1,l2)]=='*'){
			dp[min(l1,l2)][0]=dp[min(l1,l2)][1]=1;
		}
		else if(a[0][min(l1,l2)]=='*'){
			dp[min(l1,l2)][0]=0;
			dp[min(l1,l2)][1]=1;
		}
		else{
			dp[min(l1,l2)][0]=1;
			dp[min(l1,l2)][1]=0;
		}
		for(int i=min(l1,l2)+1;i<=max(r1,r2);++i){
			if(a[0][i]=='*'&&a[1][i]=='*'){
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
			}
			else if(a[0][i]=='*'){
				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
			}
			else if(a[1][i]=='*'){
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
			}
			else{
				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
			}
		}
		cout<<min(dp[max(r1,r2)][0],dp[max(r1,r2)][1])<<"\n";
	}
	
	return 0;
}