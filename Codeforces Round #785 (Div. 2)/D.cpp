#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
long long lcm(long long x,long long y){
	return x/gcd(x,y)*y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long b,q,y,c,r,z;
		cin>>b>>q>>y>>c>>r>>z;
		if(r%q||(c-b)%q){
			printf("0\n");
			continue;
		}
		if(c<b||(c+(z-1)*r-b)/q+1>y){
			printf("0\n");
			continue;
		}
		if(c-r<b||(c+z*r-b)/q+1>y){
			printf("-1\n");
			continue;
		}
		long long ans=0;
		for(long long i=1;i*i<=r;++i){
			if(r%i)continue;
			long long gap=lcm(i,q);
			if(gap==r)ans=(ans+(r/i*r/i)%mod)%mod;
			if(i*i!=r){
				gap=lcm(r/i,q);
				if(gap==r)ans=(ans+(i*i)%mod)%mod; 
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}