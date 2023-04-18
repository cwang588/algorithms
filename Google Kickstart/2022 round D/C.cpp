#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int a[2505],b[2505];
long long dp[2505][2505],l[2505][2505],r[2505][2505];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>b[i];
		int m;
		cin>>m;
		for(int i=1;i<=m;++i)cin>>a[i];
		for(int i=1;i<=m;++i){
			if(a[i]==b[1])dp[1][i]=0;
			else dp[1][i]=inf;
		}
		for(int i=2;i<=n;++i){
			l[i][0]=r[i][m+1]=inf;
			for(int j=1;j<=m;++j)l[i][j]=min(l[i][j-1],dp[i-1][j]-j);
			for(int j=m;j>=1;--j)r[i][j]=min(r[i][j+1],dp[i-1][j]+j);
			for(int j=1;j<=m;++j){
				if(a[j]!=b[i])dp[i][j]=inf;
				else dp[i][j]=min(l[i][j]+j,r[i][j]-j);
			}
		}
		long long ans=inf;
		for(int i=1;i<=m;++i)ans=min(ans,dp[n][i]);
		printf("Case #%d: %I64d\n",Case,ans);
	}
	return 0;
}