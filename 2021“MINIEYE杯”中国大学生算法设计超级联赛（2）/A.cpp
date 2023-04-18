#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		n%=mod;
		long long ans=n;
		ans=ans*n%mod;
		ans=ans*(n-1)%mod;
		ans=ans*(n-1)%mod;
		ans=ans*2%mod;
		cout<<ans<<endl;
	}
	return 0;
}
