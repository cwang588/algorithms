#include<bits/stdc++.h>
using namespace std;
long long calc(long long a,long long b,long long c){
	return max(0ll,max(b,c)+1-a);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b,c;
		cin>>a>>b>>c;
		cout<<calc(a,b,c)<<" "<<calc(b,a,c)<<" "<<calc(c,a,b)<<"\n";
	}
	
	
	return 0;
}