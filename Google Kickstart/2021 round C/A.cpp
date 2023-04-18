#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
char a[100005];
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
	for(int Case=1;Case<=t;++Case){
		int k,n;
		cin>>n>>k>>a+1;
		long long ans=0;
		for(int i=1;i<=(n+1)/2;++i)ans=(ans+quickpower(k,(n+1)/2-i,mod)*(a[i]-'a')%mod)%mod;
		bool ky=false;
		for(int i=(n+1)/2+1;i<=n;++i){
			if(a[i]<a[n-i+1]){
				ky=false;
				break;
			}
			if(a[i]>a[n-i+1]){
				ky=true;
				break;
			}
		}
		if(ky)++ans;
		cout<<"Case #"<<Case<<": "<<ans%mod<<"\n";
	}
	
	return 0;
}