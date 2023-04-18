#include<bits/stdc++.h>
using namespace std;
vector<long long>a[300005]; 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i)a[i].clear();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				long long now;
				cin>>now;
				a[j].push_back(now);
			}
		}
		for(int i=1;i<=m;++i)sort(a[i].begin(),a[i].end());
		long long ans=0;
		for(int i=1;i<=m;++i){
			long long tot=a[i][0];
			for(int j=1;j<a[i].size();++j){
				ans+=a[i][j]*j-tot;
				tot+=a[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
