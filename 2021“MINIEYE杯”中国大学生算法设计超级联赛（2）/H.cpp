#include<bits/stdc++.h>
using namespace std;
map<string,int>id;
vector<pair<int,int> >v[55];
int dp[55][505],f[55][505][5];
bool usd[55][505][5];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		id.clear();
		memset(dp,0,sizeof(dp));
		memset(usd,0,sizeof(usd));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;++i)v[i].clear();
		for(int i=1;i<=n;++i){
			string t;
			cin>>t;
			id[t]=i;	
		}
		int m;
		cin>>m;
		for(int i=1;i<=m;++i){
			string t;
			int x,y;
			cin>>t>>x>>y;
			v[id[t]].push_back(make_pair(x,y));
		}
		int t,p;
		cin>>t>>p;
		for(int i=1;i<=n;++i){
			for(int j=0;j<v[i].size();++j){
				for(int k=t;k>=v[i][j].second;--k){
					dp[i][k]=max(dp[i][k],dp[i][k-v[i][j].second]+v[i][j].first);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=t;++j){
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
				dp[i][j]=min(100,dp[i][j]);
			}
		}
		int ans=0;
		usd[0][0][0]=true;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=t;++j){
				for(int g=0;g<=p;++g){
					for(int k=j;k<=t;++k){
						if(dp[i][j]<60){
							if(g){
								if(usd[i-1][k-j][g-1]){
									f[i][k][g]=max(f[i][k][g],f[i-1][k-j][g-1]+dp[i][j]);
									usd[i][k][g]=true;
								}
//								if(usd[i-1][k][g]){
//									f[i][k][g]=max(f[i][k][g],f[i-1][k][g]);
//									usd[i][k][g]=true;
//								}
							}
						}
						else{
								if(usd[i-1][k-j][g]){
									f[i][k][g]=max(f[i][k][g],f[i-1][k-j][g]+dp[i][j]);
									usd[i][k][g]=true;
								}
//								if(usd[i-1][k][g]){
//									f[i][k][g]=max(f[i][k][g],f[i-1][k][g]);
//									usd[i][k][g]=true;
//								}
						}
						//ans=max(ans,f[i][k][g]);	
					}
				}
				for(int g=0;g<=p;++g){
					for(int k=1;k<=t;++k){
						if(usd[i][k-1][g]){
							f[i][k][g]=max(f[i][k][g],f[i][k-1][g]);
							usd[i][k][g]=true;
						}
					}
				}
			}
		}
		for(int i=0;i<=t;++i){
			for(int g=0;g<=p;++g)
				if(usd[n][i][g])ans=max(ans,f[n][i][g]);	
		}
		if(!ans)cout<<"-1\n";
		else cout<<ans<<endl;
	}
	return 0;
}
