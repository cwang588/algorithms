#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[755][755],p[10005],dp[10005][755];
int main(){
	int k,n;
	long long L;
	cin>>k>>L;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=k;++j)cin>>a[i][j];
	}
	cin>>n;
	for(int i=1;i<n;++i)cin>>p[i];
	dp[1][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
			int l=lower_bound(a[j]+1,a[j]+1+k,p[i]-L)-(a[j]+1)+1;
			int r=upper_bound(a[j]+1,a[j]+1+k,p[i]+L)-(a[j]+1);
			if(l>r)continue;
			dp[i+1][l]=(dp[i+1][l]+dp[i][j])%mod;
			dp[i+1][r+1]=(dp[i+1][r+1]-dp[i][j])%mod;
		} 
	}
	long long ans=0;
	for(int i=1;i<=k;++i)ans=(ans+dp[n][i])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
