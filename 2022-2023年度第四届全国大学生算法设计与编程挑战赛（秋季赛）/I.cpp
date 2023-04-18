#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long num[10000005];
bool isprime[10000005];
long long mi[10000007];
void init(){
	for(int i=2;i<=10000000;++i){
		if(!isprime[i]){
			++num[i];
			for(int j=2;j*i<=10000000;++j){
				isprime[i*j]=true;
				++num[i*j];
			}			
		}
	}
	mi[0]=1;
	for(int i=1;i<=10000000;++i)mi[i]=mi[i-1]*3%mod;
}

int main(){
	init();
	long long ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)ans=(ans+mi[num[i]])%mod;
	cout<<ans<<"\n";
	return 0;
}