#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
vector<int>p;
int work(int x){
	int re=0;
	while(x){
		re=re*10+x%10;
		x/=10;
	}
	return re;
}
long long dp[40005];
void init(){
	for(int i=1;i<=40000;++i){
		if(work(i)==i)p.push_back(i);
	}
	dp[0]=1;
	for(auto x:p){
		for(int i=x;i<=40000;++i)dp[i]=(dp[i-x]+dp[i])%mod;
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	
	
	return 0;
}