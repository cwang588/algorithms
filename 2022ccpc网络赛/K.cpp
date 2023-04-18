#include<bits/stdc++.h>
using namespace std;
long long a[2005][2005],sum[2005][2005],dp[2005][2005];
vector<int>pos[2005];
char b[2005][2005];
int main(){
	int t=1;
//	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j]>>b[i][j];
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j)sum[j][i]=sum[j-1][i]+a[j][i];
		}
		long long ans=0;
		int totnum=0;
		for(int i=1;i<=m;++i){
			pos[i].clear();
			for(int j=n;j>=1;--j){
				if(b[j][i]=='N')break;
				ans+=a[j][i];
			}
			for(int j=n;j>=1;--j){
				if(b[j][i]=='N')pos[i].push_back(j);
			}
			totnum+=pos[i].size();
			pos[i].push_back(0);
	//		for(auto x:pos[i])cout<<x<<" ";
	//		cout<<endl;
		}
		if(totnum<k){
			long long tmpans=0;
			for(int i=1;i<=m;++i)tmpans+=sum[n][i];
			cout<<tmpans<<endl;
			continue;
		}
		for(int i=1;i<=m;++i){
			for(int j=0;j<=k;++j){
				dp[i][j]=dp[i-1][j];
			//	if(pos[i].size()==1)continue;
				for(int g=1;g<=min((int)(pos[i].size()-1),j);++g){
					if(j==k){
						int l=pos[i][0],r=pos[i][g-1]-1;
						dp[i][j]=max(dp[i][j],dp[i-1][j-g]+sum[l][i]-sum[r][i]);
					}
					else{
						int l=pos[i][0],r=pos[i][g];
						dp[i][j]=max(dp[i][j],dp[i-1][j-g]+sum[l][i]-sum[r][i]);
					}
				}
			}
		}
		cout<<ans+dp[n][k]<<endl;
	}	
	return 0;
}
