#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length(),cnt1=0,cnt2=0,ans=0;
		for(int i=0;i<n;++i){
			if(s[i]=='(')++cnt1;
			if(s[i]=='[')++cnt2;
			if(s[i]==')'){
				if(cnt1){
					++ans;
					--cnt1;
				}
			}
			if(s[i]==']'){
				if(cnt2){
					++ans;
					--cnt2;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
