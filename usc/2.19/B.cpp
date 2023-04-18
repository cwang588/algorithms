#include<bits/stdc++.h>
using namespace std;
vector<int>a[25];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			a[i].clear();
			a[i].push_back(i-1);
			int m;
			cin>>m;
			while(m--){
				int now;
				cin>>now;
				a[i].push_back(now-1);
			}
		}
		int ans=2147483647;
		for(int i=0;i<(1<<n);++i){
			int cnt=0,state=0;
			for(int j=0;j<n;++j){
				if(i&(1<<j)){
					++cnt;
					for(const auto &x:a[j+1])state|=(1<<x);
				}
			}
			if(state==(1<<n)-1)ans=min(ans,cnt);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}