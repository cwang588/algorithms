#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,r;
		cin>>n>>l>>r;
		bool ky=true;
		vector<int>ans;
		for(int i=1;i<=n;++i){
			if(r/i*i<l)ky=false;
			ans.push_back(r/i*i);
		}
		if(!ky)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(auto x:ans)cout<<x<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}