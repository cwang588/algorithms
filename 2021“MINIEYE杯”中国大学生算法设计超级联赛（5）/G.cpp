#include<bits/stdc++.h>
const long long mod=1000000007;
using namespace std;
long long quickpower(long long a,long long b,long long p){
	long long ans=1,now=a;
	while(b){
		if(b&1)ans=ans*now%mod;
		now=now*now%mod;
		b>>=1; 
	}
	return ans;
}
int main(){
//	for(int n=1;n<=100;++n){
//		long long a=n*(2*n+1)*(n+1)*(n+1)/6-n*n*(n+1)*(n+1)/4;
//		long long b=n*(2*n+1)*(n+1)/6-1+(n+2)*(n-1)/2;
//		cout<<n<<":";
//		if(a>b)cout<<"a>b\n";
//		else if(a==b)cout<<"a==b\n";
//		else cout<<"a<b\n";
//	}
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		n%=mod;
		long long ans=n;
		ans=ans*(2*n+1)%mod;
		ans=ans*(n+1)%mod;
		ans=ans*quickpower(6,mod-2,mod)%mod;
		ans=(ans-1+mod)%mod;
		ans=(ans+((n+2)*(n-1)%mod)*quickpower(2,mod-2,mod)%mod)%mod;
		ans=ans*(((n+2)*(n-1)%mod)*quickpower(2,mod-2,mod)%mod)%mod;
		ans=(ans+(((((n*n%mod)*(n+1)%mod)*(n+1)%mod)*(2*n+1)%mod)%mod)*quickpower(12,mod-2,mod)%mod)%mod;
		cout<<ans<<endl;
		ans=(((((n*n%mod)*(n+1)%mod)*(n+1)%mod)*(2*n+1)%mod)%mod)*quickpower(12,mod-2,mod)%mod;
		ans=(ans*n%mod)*n%mod;
		cout<<ans<<endl;
	}
	return 0; 
}
