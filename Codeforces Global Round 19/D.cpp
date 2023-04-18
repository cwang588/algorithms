#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool dp[105][20005];
int main(){
	int t;
	cin>>t;
	dp[0][10000]=true;
	while(t--){
		int n;
		cin>>n;
		long long tot1=0,tot2=0;
		for(int i=1;i<=n;++i)cin>>a[i],tot1+=a[i],tot2+=a[i]*a[i];
		for(int i=1;i<=n;++i)cin>>b[i],tot1+=b[i],tot2+=b[i]*b[i];
		for(int i=1;i<=n;++i)memset(dp[i],0,sizeof(dp[i]));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=20000;++j){
				if(!dp[i-1][j])continue;
				dp[i][j+a[i]-b[i]]=dp[i][j+b[i]-a[i]]=true;
			}
		}
		long long ans=0;
		for(int i=0;i<=10000;++i){
			if(dp[n][10000-i]||dp[n][10000+i]){
				long long x=(tot1-i)/2,y=(tot1+i)/2;
				ans=x*x+y*y;
				break;
			}
		}
		ans+=tot2*(n-2);
		cout<<ans<<"\n";
	}
	return 0;
}