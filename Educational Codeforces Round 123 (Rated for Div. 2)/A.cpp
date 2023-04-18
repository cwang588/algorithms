#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int a=0,b=0,c=0;
		bool ky=true;
		for(auto x:s){
			if(x=='R')--a;			
			if(x=='G')--b;			
			if(x=='B')--c;			
			if(x=='r')++a;			
			if(x=='g')++b;			
			if(x=='b')++c;			
			if(a<0||b<0||c<0){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}