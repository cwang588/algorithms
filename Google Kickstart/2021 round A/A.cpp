#include<bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,k,cnt=0;
		cin>>n>>k>>s+1;
		for(int i=1;i<=n/2;++i){
			if(s[i]!=s[n-i+1])++cnt;
		}
		cout<<"Case #"<<Case<<": "<<abs(cnt-k)<<"\n";
	}
	
	
	
	return 0;
}