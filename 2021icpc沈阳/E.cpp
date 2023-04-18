#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i+4<s.length();++i){
		if(s.substr(i,5)=="edgnb")++cnt;
	}
	cout<<cnt;
	return 0;
}