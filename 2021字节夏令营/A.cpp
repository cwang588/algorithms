#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005],dp[100005][2];
void dfs(int now){
	if(now>n)return;
	dfs(now<<1);
	dfs(now<<1|1);
	dp[now][0]=max(dp[now<<1][0],dp[now<<1][1])+max(dp[now<<1|1][0],dp[now<<1|1][1]);
	dp[now][1]=dp[now<<1][0]+dp[now<<1|1][0]+a[now];
}
int main(){
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
	return 0;
}
