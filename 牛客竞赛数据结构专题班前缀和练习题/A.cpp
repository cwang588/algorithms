#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[100005];
long long quickpower(long long a,long long b,long long p){
	long long now=a,ans=1;
	while(b){
		if(b&1)ans=ans*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	a[0]=1;
	for(int i=1;i<=n;++i)cin>>a[i],a[i]=a[i-1]*a[i]%mod;
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		cout<<a[r]*quickpower(a[l-1],mod-2,mod)%mod<<endl;
	}
	return 0;
}
