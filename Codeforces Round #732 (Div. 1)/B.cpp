#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long fac[100005],inv[100005];
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=100000;++i)fac[i]=fac[i-1]*i%mod;
	inv[100000]=quickpower(fac[100000],mod-2,mod);
	for(int i=100000;i>=1;--i)inv[i-1]=inv[i]*i%mod;
}
long long C(int n,int m){
	long long ans=1;
	ans=ans*fac[n]%mod;
	ans=ans*inv[m]%mod;
	ans=ans*inv[n-m]%mod;
	return ans;
}
bool usd[1000005];
int main(){
	int t;
	cin>>t;
	init();
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int cnt1=0,cnt2=0;
		for(int i=0;i<s.length();++i){
			if(s[i]=='0')++cnt1;
			if(i>0&&s[i]=='1'){
				if(s[i-1]=='1'&&!usd[i-1]){
					++cnt2;
					usd[i]=true;
				}
			}
		}
		cout<<C(cnt1+cnt2,cnt1)<<endl;
		for(int i=0;i<s.length();++i){
			usd[i]=false;
		}
	}
	return 0;
}
