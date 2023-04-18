#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
char a[5005],b[505];
long long dp[5005];
long long c[5005][5005];
int main(){
	int n,m;
	cin>>n>>m>>(a+1)>>(b+1);
	dp[0]=1;
	long long ans=0;
	for(int i=0;i<=5000;++i)c[i][0]=1;
	for(int i=1;i<=5000;++i){
		for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j){
			if(a[i]<b[j])ans=(ans+c[n-i][m-j]*dp[j-1]%mod)%mod;
			else if(a[i]==b[j])dp[j]=(dp[j-1]+dp[j])%mod;
			else;
		}
	}
	cout<<ans;
	return 0;
}
