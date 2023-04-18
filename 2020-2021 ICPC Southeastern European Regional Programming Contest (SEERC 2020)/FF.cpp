#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int a[3005],l[3005],r[3005];
long long dp[3005][3005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		l[i]=0,r[i]=n+1;
		for(int j=i-1;j>=1;--j){
			if(a[j]<a[i]){
				l[i]=j;
				break;
			}
		}
		for(int j=i+1;j<=n;++j){
			if(a[j]<a[i]){
				r[i]=j;
				break;
			}
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=l[i]+1;j<=r[i]-1;++j){
			dp[i][j]+=dp[i][j-1];
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}
