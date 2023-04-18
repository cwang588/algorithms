#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long quickpower(long long a,long long b,long long k){
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
	scanf("%d",&t);
	while(t--){
		long long n,k;
		cin>>n>>k;
		cout<<quickpower(n,k,mod)<<"\n";
	}
	return 0;
}
