#include<bits/stdc++.h>
using namespace std;
bool check(string &a,string b){
	unordered_map<char,bool>usd;
	unordered_map<char,int>num;
	for(const auto &c:b)usd[c]=true,++num[c];
	for(const auto &c:a){
		if(!usd[c])return false;
	}
	return num[b[0]]==1&&num[b[b.length()-1]]==1;
}
map<string,bool>cnt;
int main(){
	string s;
	while(cin>>s){	
		cnt.clear();
		int n=s.length(),ans=0;
		for(int i=0;i<n;++i){
			for(int j=1;i+j-1<n;++j){
				auto now=s.substr(i,j);
				if(check(s,now)){
					if(j!=n){
						if(!cnt[now])++ans;
						cnt[now]=true;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}