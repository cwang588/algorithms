#include<bits/stdc++.h>
using namespace std;
map<string,bool>usd;
string a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		usd.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],usd[a[i]]=true;;
		for(int i=1;i<=n;++i){
			bool ky=false;
			for(int j=1;j<a[i].length();++j){
				if(usd[a[i].substr(0,j)]&&usd[a[i].substr(j,a[i].length()-j)]){
					ky=true;
					break;
				}
			}
			if(ky)cout<<"1";
			else cout<<"0";
		}
		cout<<"\n";
	}
	
	
	return 0;
}