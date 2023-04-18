#include<bits/stdc++.h>
using namespace std;
int dp[100005];
bool check(int x,int num){
	int cnt=0;
	while(x){
		x/=10;
		++cnt;
	}
	return cnt==num;
}
int main(){
	int n;
	cin>>n;
	dp[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]+1;
		for(int j=1;j*2<=i;++j)dp[i]=min(dp[i],dp[j]+dp[i-j]);
		for(int j=1;j*j<=i;++j){
			if(i%j==0)dp[i]=min(dp[i],dp[j]+dp[i/j]);
		}
		int now=1;
		for(int j=1;;++j){
			now*=10;
			if(now>=i)break;
			if(check(i%now,j))dp[i]=min(dp[i],dp[i/now]+dp[i%now]);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}