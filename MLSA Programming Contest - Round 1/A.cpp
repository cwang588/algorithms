#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1005];
void init(){
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=1000;++i){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	
	return 0;
}
