#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		string s;
		cin>>s;
		int n=s.length(),mod=0;
		for(auto c:s)mod=(mod+c-'0')%9;
		mod=(9-mod)%9;
		cout<<"Case #"<<Case<<": ";
		bool ky=false;
		for(auto c:s){
			int now=c-'0';
			if(ky)cout<<now;
			else{
				if(now>mod){
					ky=true;
					if(mod)cout<<mod<<now;
					else cout<<now<<mod;
				}
				else cout<<now;
			}
		}
		if(!ky)cout<<mod;
		cout<<"\n";
	}
	
	return 0;
}