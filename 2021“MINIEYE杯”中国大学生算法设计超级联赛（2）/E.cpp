#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1; 
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int tot=0;
		for(int i=1;i<s.length();++i){
			if(s[i]==s[i-1])++tot;
			else break;
		}
		cout<<quickpower(2,tot,mod)<<endl;
	}
	return 0;
}
