#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,l,r;
		cin>>n>>l>>r;
		if(r-l>=2*n-2)cout<<(quickpower(n,n-2,mod)*(r-l+1)-1+mod)%mod<<endl;
		else{
			long long ans=0;
			for(it i)
		}
	}
	return 0;
}
