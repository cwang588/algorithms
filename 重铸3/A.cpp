#include<bits/stdc++.h>
using namespace std;
char s[105];
int dp[105];
int main(){
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)dp[i]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j){
			if(s[j]<s[i])dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	cout<<26-ans<<endl;
	return 0;
}
