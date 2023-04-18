#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
char s[100005];
long long tot[9],num[100005],mi[1000005];
int main(){
	int t;
	cin>>t;
	mi[0]=1;
	for(int i=1;i<=100000;++i)mi[i]=mi[i-1]*2%mod;
	while(t--){
		cin>>(s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n+1;++i){
			num[i]=0;
		}
		memset(tot,0,sizeof(tot));
		long long ans=0;
		for(int i=n;i>=1;--i){
			num[i]=num[i+1];
			if(s[i]=='a')++num[i];
		}
		for(int i=1;i<=n;++i){
			if(s[i]=='n'){
				++tot[0];
				tot[2]=(tot[2]+tot[1])%mod;
			}
			else if(s[i]=='u')tot[1]+=tot[0];
			else if(s[i]=='h'){
				tot[3]=(tot[3]+tot[2])%mod;
				tot[6]=(tot[6]+tot[5])%mod;
				tot[5]=(tot[5]+tot[4])%mod;
				ans=(ans+tot[7]*(mi[num[i+1]]-1)%mod)%mod;
			}
			else if(s[i]=='e'){
				tot[4]=(tot[4]+tot[3])%mod;
				tot[7]=(tot[7]+tot[6])%mod;
			}
			else;
		}
		cout<<(ans%mod+mod)%mod<<"\n";
	}
	return 0;
}