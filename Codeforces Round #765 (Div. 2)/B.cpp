#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >m;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		m.clear();
		for(int i=1;i<=n;++i){
			int now;
			cin>>now;
			m[now].push_back(i);
		}
		int ans=0;
		for(auto x:m){
			auto a=x.second;
			for(int i=0;i<a.size()-1;++i)ans=max(ans,a[i]+n-a[i+1]);
		}
		if(ans>0)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}