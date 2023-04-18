#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[65][6];
int main(){
	int n;
	cin>>n;
	--n;
	for(int i=0;i<6;++i)dp[0][i]=1;
	for(int i=1;i<=n;++i){
		long long tot=0;
		for(int j=0;j<6;++j)tot+=dp[i-1][j];
		tot%=mod;
		for(int j=0;j<6;++j){
			dp[i][j]=(tot-dp[i-1][j]-dp[i-1][j])*(tot-dp[i-1][j]-dp[i-1][j])%mod;
		}
	}
	long long ans=0;
	for(int j=0;j<6;++j)ans+=dp[n][j];
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}