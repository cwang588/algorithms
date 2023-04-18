#include<bits/stdc++.h>
using namespace std;
int a[105];
bitset<50005>dp[55];
int main(){
	int n;
	cin>>n;
	int tot=0;
	for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
	dp[0].set(0);
	for(int i=1;i<=n;++i){
		for(int j=n/2;j>=1;--j)dp[j]|=(dp[j-1]<<a[i]);
	}
	int Min=2147483647,ans;
	for(int i=0;i<=50000;++i){
		if(dp[n/2][i]){
			if(abs(2*i-tot)<Min){
				Min=abs(2*i-tot);
				ans=i;
			}
		}
	}
	cout<<min(ans,tot-ans)<<" "<<max(ans,tot-ans);
	return 0;
}