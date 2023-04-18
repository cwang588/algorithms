#include<bits/stdc++.h>
using namespace std;
const long long mod=1000007;
int a[1005];
long long dp[1005][15];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),dp[i][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			if(a[i]<=a[j])continue;
			for(int k=2;k<=10;++k){
				dp[i][k]+=dp[j][k-1];
				dp[i][k]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=dp[i][m];
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
