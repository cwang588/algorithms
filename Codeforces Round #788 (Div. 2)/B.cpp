#include<bits/stdc++.h>
using namespace std;
bool usd[35];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(usd,0,sizeof(usd));
		int n;
		string s;
		cin>>n>>s;
		int m;
		cin>>m;
		while(m--){
			char tmp;
			cin>>tmp;
			usd[tmp-'a'+1]=true;
		}
		vector<int>pos;
		pos.push_back(0);
		for(int i=0;i<n;++i){
			if(usd[s[i]-'a'+1])pos.push_back(i);
		}
		int ans=0;
		for(int i=1;i<pos.size();++i)ans=max(ans,pos[i]-pos[i-1]);
//		if(pos.size()>1)ans=max(ans,pos[pos.size()-1]-pos[pos.size()-2]-1);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}