#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		unordered_map<char,int>num;
		string s;
		cin>>s;
		for(const auto &c:s)++num[c];
		if(s.length()==5&&num['B']&&num['a']&&num['i']&&num['d']&&num['u'])cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	
	return 0;
}