#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	string s=to_string(x);
	for(int i=0;i<s.length();++i){
		if(s[i]!=s[s.length()-1-i])return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		long long n;
		cin>>n;
		int ans=0;
		for(long long i=1;i*i<=n;++i){
			if(n%i==0){
				if(check(i))++ans;
				if(i*i!=n&&check(n/i))++ans;
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	
	return 0;
}