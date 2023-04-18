#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool ky=false;
		for(int i=0;i<s.length();++i){
			if(s.substr(i,6)=="114514"){
				ky=true;
				break;
			}
		}
		if(ky)cout<<"AAAAAA\n";
		else cout<<"Abuchulaile\n";
	}
	
	return 0;
}
