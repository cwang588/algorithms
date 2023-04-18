#include<bits/stdc++.h>
const long long mod=1000000007;
using namespace std;
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		if(n%2==0){
			long long tmp=quickpower(2,n-1,mod),ans=quickpower(tmp-1,k,mod);
			for(int i=1;i<=k;++i)ans=(ans+quickpower(tmp-1,i-1,mod)*quickpower(2,n*(k-i),mod)%mod)%mod;
			cout<<ans<<endl;
		}
		else cout<<quickpower((quickpower(2,n-1,mod)+1)%mod,k,mod)<<endl;
	}
	return 0;
}
