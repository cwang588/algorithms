#include<bits/stdc++.h>
using namespace std;
bool usd[67];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(usd,0,sizeof(usd));
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans=0;
		for(auto c:s){
			if(!usd[c-'A']){
				ans+=2;
				usd[c-'A']=true;
			}
			else ++ans;
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}