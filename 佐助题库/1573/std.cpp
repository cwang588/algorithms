#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("15735.in","r",stdin);
	//freopen("15735.out","w",stdout);
	string s;
	getline(cin,s);
	int n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]>='A'&&s[i]<'Z')++s[i];
		else if(s[i]=='Z')s[i]='A';
		else if(s[i]>='a'&&s[i]<'z')++s[i];
		else if(s[i]=='z')s[i]='a';
		else;
		cout<<s[i];
	}
	return 0;
}
