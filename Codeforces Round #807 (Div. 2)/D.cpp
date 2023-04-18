#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >work(string s){
	int last=0;
	vector<pair<int,int> >re;
	for(int i=1;i<s.length();++i){
		if(s[i]!=s[i-1]){
			re.push_back(make_pair(i-last,s[i-1]-'0'));
			last=i;
		}
	}
	re.push_back(make_pair(s.length()-last,s[s.length()-1]-'0'));
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string a,b;
		cin>>n>>a>>b;
		auto x=work(a),y=work(b);
		if(x.size()!=y.size()){
			cout<<"-1\n";
			continue;
		}
		long long ans=0;
		bool ky=true;
		int m=x.size();
		for(int i=0;i<m;++i){
			if(x[i].second!=y[i].second){
				ky=false;
				break;
			}
			ans+=abs(x[i].first-y[i].first);
			if(i<m-1)x[i+1].first-=y[i].first-x[i].first;
		}
		if(ky)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}