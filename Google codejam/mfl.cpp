#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int n;
	cin>>s>>n;
	while(n--){
		string op;
		cin>>op;
		if(op[0]=='0')reverse(s.begin()+(op[1]-'0'),s.begin()+(op[1]-'0')+(op[2]-'0'));
		else s.replace(op[1]-'0',op[2]-'0',op.substr(3,op.length()-3));
		cout<<s<<"\n";
	}
	return 0;
}