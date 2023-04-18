#include<bits/stdc++.h>
using namespace std;
int n,a[200005],sum[200005],cnt[200005],pos[200005];
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	while(x<=n){
		++sum[x];
		x+=lowbit(x);
	}
}
int query(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
long long dp[200005][2];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],pos[a[i]]=i;
	for(int i=n;i>=1;--i){
		cnt[a[i]]=query(a[i]);
		add(a[i]);
	}
	pos[n+1]=n+1;
	dp[0][1]=2147483647; 
	for(int i=1;i<=n;++i){
		if(pos[i]<pos[i-1]){
			dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1])+cnt[i]-1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+cnt[i];
		}
		else{
			dp[i][0]=dp[i][1]=min(dp[i-1][0],dp[i-1][1])+cnt[i];
		}
	}
	cout<<min(dp[n][0],dp[n][1])<<endl;
	return 0;
}
