#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		p.clear();
		p.push_back(-1);
		for(int i=0;i<s.length();++i)if(s[i]=='+')p.push_back(i);
		bool ky=true;
		for(int i=0;i<p.size();++i){
			int now=p[i]+1;
			if(s[now]=='0')continue;
			if(now+2>=s.length()||s[now+1]!='/'||s[now+2]!='x'){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
