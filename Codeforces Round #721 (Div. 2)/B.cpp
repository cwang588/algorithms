#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,num=0;
		cin>>n;
		char tmp;
		for(int i=1;i<=n;++i){
			cin>>tmp;
			if(tmp=='0')++num;
		}
		if(num==0)cout<<"DRAW\n";
		else if(num>0&&num%2==0)cout<<"BOB\n";
		else if(num==1)cout<<"BOB\n";
		else cout<<"ALICE\n";
	}
	return 0;
}
