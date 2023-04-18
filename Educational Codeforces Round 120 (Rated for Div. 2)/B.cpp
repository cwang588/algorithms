#include<bits/stdc++.h>
using namespace std;
int a[200005],ans[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		string s;
		cin>>s;
		vector<pair<int,int> >v0,v1;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='0')v0.push_back(make_pair(a[i],i)),++cnt;
			else v1.push_back(make_pair(a[i],i));
		}
		sort(v0.begin(),v0.end());
		sort(v1.begin(),v1.end());
		for(int i=0;i<cnt;++i){
			ans[v0[i].second]=i+1;
		}
		for(int i=0;i<n-cnt;++i){
			ans[v1[i].second]=i+1+cnt;
		}
		for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}