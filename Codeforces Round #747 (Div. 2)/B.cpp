#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long mi[105],mi2[105];
int main(){
	int t;
	cin>>t;
	mi2[0]=1;
	for(int i=1;i<=32;++i)mi2[i]=mi2[i-1]*2;
	while(t--){
		int n;
		long long k;
		cin>>n>>k;
		mi[0]=1;
		long long ans=0;
		for(int i=1;i<=32;++i)mi[i]=mi[i-1]*n%mod;
		for(int i=32;i>=0;--i){
			if(k>=mi2[i]){
				ans+=mi[i];
				ans%=mod;
				k-=mi2[i];
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}