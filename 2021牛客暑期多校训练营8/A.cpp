#include<bits/stdc++.h>
using namespace std;
const long long mod=4933;
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
	int n,m,a,k,l;
	cin>>n>>m>>k>>a>>l;
	long long ans=1;
	for(int i=1;i<=k;++i){
		int x,y,z;
		cin>>x>>y>>z;
		if(!x)continue;
		ans=ans*(z-y)*quickpower(z,mod-2,mod)%mod;
	}
	cout<<(ans+a)%mod<<endl;
	return 0;
}
