#include<bits/stdc++.h>
using namespace std;
long long dp[55][55];
int main(){
	int n;
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			for(int k=0;k<=min(j,i-j);++k)dp[i][j]+=dp[i-j][k];
		}
	}
	long long tot=0;
	for(int i=1;i<=n;++i)tot+=dp[n][i];
	cout<<tot;
	return 0;
}