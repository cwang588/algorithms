#include<bits/stdc++.h>
using namespace std;
bool judge(int a,int b,int c){
	if(a+b==c||a+c==b||b+c==a)return true;
	if(a==b&&c%2==0)return true;
	if(a==c&&b%2==0)return true;
	if(b==c&&a%2==0)return true;
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(judge(a,b,c))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}