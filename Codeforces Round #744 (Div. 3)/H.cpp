#include<bits/stdc++.h>
using namespace std;
const int inf=19260817;
int a[10005],dp[2005],tmp[2005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		dp[0]=0;
		for(int i=1;i<=2000;++i)dp[i]=inf;
		for(int i=0;i<=2000;++i)tmp[i]=inf;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=2000;++j){
				if(dp[j]==inf)continue;
				if(a[i]>=dp[j]){
					if(j+a[i]<=2000)tmp[0]=min(tmp[0],j+a[i]);
				}
				else{
					tmp[dp[j]-a[i]]=min(tmp[dp[j]-a[i]],a[i]+j);
				}
				if(a[i]>=j){
					if(a[i]+dp[j]<=2000)tmp[0]=min(tmp[0],dp[j]+a[i]);
				}
				else{
					tmp[j-a[i]]=min(tmp[j-a[i]],a[i]+dp[j]);
				}
			}
			for(int i=0;i<=2000;++i)dp[i]=tmp[i],tmp[i]=inf;
		}
		int ans=inf;
		for(int i=0;i<=2000;++i)ans=min(ans,i+dp[i]);
		cout<<ans<<"\n";
	}
	return 0;
}
