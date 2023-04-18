#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		long long x,y;
		cin>>x>>y;
		long long tmp=x*5+y;
		if(tmp==0){
			cout<<"0\n";
			continue;
		}
		vector<int>ans;
		while(tmp){
			ans.push_back(tmp&1);
			tmp>>=1;
		}
		reverse(ans.begin(),ans.end());
		for(auto x:ans)cout<<x;
		cout<<"\n";
	}
	
	return 0;
}