#include<bits/stdc++.h>
using namespace std;
vector<int>pos[28];
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		for(int i=0;i<26;++i)pos[i].clear();
		for(int i=0;i<n;++i)pos[s[i]-'a'].push_back(i+1);
		int l=s[0]-'a',r=s[n-1]-'a',tot=0;
		vector<int>ans;
		if(l<r){
			for(int i=l;i<=r;++i){
				tot+=pos[i].size();
				for(const auto &x:pos[i])ans.push_back(x);
			}
		}else{
			for(int i=l;i>=r;--i){
				tot+=pos[i].size();
				for(const auto &x:pos[i])ans.push_back(x);
			}
		}
		cout<<abs(l-r)<<" "<<tot<<"\n";
		for(const auto &x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	return 0;
}