#include<bits/stdc++.h>
using namespace std;
const int mod=31607;
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
long long a[25][25],tot1[25],tot2[25];
int main(){
	int n;
	cin>>n;
	long long bkx=quickpower(10000,mod-2,mod);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			tot1[i]=tot2[i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			long long t;
			cin>>t;
			a[i][j]=t*bkx%mod;
			tot1[i]=(tot1[i]*a[i][j])%mod;
			tot2[j]=(tot2[j]*a[i][j])%mod;
		}
	}
	long long ans=0;

	return 0;
}
