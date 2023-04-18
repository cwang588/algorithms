#include<bits/stdc++.h>
using namespace std;
int v[2005],w[2005],dp[2005];
int last[2005][2005];
int main(){
	int m,n;
	while(cin>>m>>n){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
		for(int i=1;i<=n;++i){
			for(int j=m;j>=w[i];--j){
				if(dp[j]<dp[j-w[i]]+v[i]){
					last[i][j]=j-w[i];
					dp[j]=dp[j-w[i]]+v[i];
				}else{
					last[i][j]=j;
				}
			}
			for(int j=0;j<w[i];++j)last[i][j]=j;
		}
		int Max=0,pos;
		for(int i=1;i<=m;++i){
			if(Max<dp[i]){
				pos=i,Max=dp[i];
			}
		}
		vector<int>ans;
		for(int i=n;i>=1;--i){
			if(last[i][pos]<pos){
				ans.push_back(i-1);
				pos=last[i][pos];
			}
		}
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(const auto &x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	return 0;
}