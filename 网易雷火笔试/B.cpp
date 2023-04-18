#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int a[10005];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(0));
		int h,l,r,n;
		cin>>h>>l>>r>>n;
		for(int i=1;i<=10000;++i)dp[i]=100000;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			for(int j=a[i];j<=10000;++j){
				dp[j]=min(dp[j],dp[j-a[i]]+1);
			}
		}
		int ans=100000;
		for(int i=h-r;i<=h-l;++i)ans=min(ans,dp[i]);
		if(ans<100000)cout<<ans<<"\n";
		else cout<<"0\n";
	}
	
	return 0;
}