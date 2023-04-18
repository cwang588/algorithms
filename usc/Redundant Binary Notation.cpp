#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[74],dp[74][205];
int main(){
	long long n;
	int m;
	cin>>n>>m;
	for(int i=0;i<=60;++i){
		a[i]=n&1;
		n/=2;
	}
	dp[61][0]=1;
	for(int i=60;i>=0;--i){
		for(int j=a[i];j<=m*2;j+=2){
			int now=(j-a[i])/2;
			for(int k=now;k<=m+now;++k)dp[i][j]=(dp[i][j]+dp[i+1][k])%mod;
		}
	}
	int ans=0;
	for(int i=0;i<=m;++i)ans=(ans+dp[0][i])%mod;
	cout<<ans<<"\n";
	return 0;
}