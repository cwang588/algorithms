#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		bool ky=false;
		int pos=-1;
		for(int i=0;i<n-1;++i){
			if(s[i]+s[i+1]-'0'*2>=10){
				ky=true;
				pos=i;
			}
		}
		if(!ky){
			cout<<(char)(s[0]+s[1]-'0');
			for(int i=2;i<n;++i)cout<<s[i];
		}
		else{
			for(int i=0;i<pos;++i)cout<<s[i];
			cout<<(int)(s[pos]+s[pos+1]-'0'*2);
			for(int i=pos+2;i<n;++i)cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}