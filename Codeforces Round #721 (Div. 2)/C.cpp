#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i];
		int num1=0,num2=0;
		for(int i=1;i*2<=n;++i){
			if(s[i]!=s[n-i+1])++num1;
			else{
				if(s[i]=='0')num2+=2;
			}
		}
		if(num1==0){
			if(n%2&&s[(n+1)/2]=='0')++num2;
			if(num2==0)cout<<"DRAW\n";
			else if(num2>0&&num2%2==0)cout<<"BOB\n";
			else if(num2==1)cout<<"BOB\n";
			else cout<<"ALICE\n";
		}
		else{
			if(n%2&&s[(n+1)/2]=='0'&&num1==1&&!num2)cout<<"DRAW\n";
			else cout<<"ALICE\n";
		}
	}
	return 0;
}
