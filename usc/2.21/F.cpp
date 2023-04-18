#include<bits/stdc++.h>
using namespace std;
int a[100005],dp[100005],pos[100005];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;++i)cin>>a[i];
		dp[1]=a[1];
		pos[1]=1;
		int len=1;
		for(int i=2;i<=n;++i){
			if(a[i]>dp[len]){
				dp[++len]=a[i];
				pos[i]=len;
			}else{
				int m=lower_bound(dp+1,dp+1+len,a[i])-dp;
				dp[m]=a[i];
				pos[i]=m;
			}
		}
		vector<int>ans;
		for(int i=n;i>=1;--i){
			if(len==pos[i]){
				ans.push_back(i-1);
				--len;
			}
		}
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(const auto &x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}