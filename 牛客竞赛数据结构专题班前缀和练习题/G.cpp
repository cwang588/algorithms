#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char s[100005];
int main(){
	int n;
	cin>>n>>(s+1);
	long long tot=0,ans=0;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0')continue;
		ans=(ans+1ll*cnt*i%mod-tot)%mod;
		tot=(tot+i)%mod;
		++cnt;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl; 
	return 0;
}
