#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[200005][2];
bool usd[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			char now;
			cin>>now;
			if(now=='1')usd[i]=true;
			else usd[i]=false;
		}
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			if(!usd[i]){
				dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=0;
			}else{
				dp[i][0]=dp[i-1][0]+a[i-1];
				dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
			}
		}
		cout<<max(dp[n][0],dp[n][1])<<"\n";
	}
	
	
	return 0;
}