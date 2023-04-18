#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[100005];
long long dp[100005][2];
bool usd[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],usd[a[i]]=true;
	dp[1][0]=1;
	for(int i=2;i<=n;++i){
		int pos=i;
		if(a[i]<i)--pos;
		if(usd[i])--pos;
		dp[i][0]=dp[i-1][0]*pos%mod;
		if(a[i]!=i){
			dp[i][0]+=dp[i-1][1];
			dp[i][0]%=mod;
			dp[i][1]=dp[i-1][0]+dp[i-1][1]*(i-1)%mod;
			dp[i][1]%=mod;
		}
		else dp[i][1]=dp[i-1][1]*i%mod;
	}
	cout<<dp[n][0];
	return 0;
}