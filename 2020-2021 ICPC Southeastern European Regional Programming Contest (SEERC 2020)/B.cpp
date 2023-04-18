#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	long long cnt=0;
	int num=0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='0')cnt+=num;
		else ++num;
	}
	if(cnt%3)cout<<"Alice\n";
	else cout<<"Bob\n";
	return 0;
}
