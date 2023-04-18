#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s+1;
		int cnt=0;
		bool yi=false;
		int len=strlen(s+1);
		for(int i=1;i<=len;++i){
			if(s[i]=='0'&&s[i]!=s[i-1])++cnt;
			if(s[i]=='1')yi=true;
		}
		if(cnt>=2)cout<<"2\n";
		else{
			if(cnt==1)cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
