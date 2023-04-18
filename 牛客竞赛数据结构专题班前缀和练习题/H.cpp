#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[100005],b[100005],c[100005];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=m;++i){
			int type,pos;
			cin>>type>>pos;
			if(type==1)++a[pos];
			else if(type==2){
				++b[pos];
				a[pos]=(a[pos]-pos+1)%mod;
			}
			else{
				++c[pos];
				b[pos]=(b[pos]-2*(pos-1))%mod;
				a[pos]=(a[pos]+1ll*(pos-1)*(pos-1))%mod;
			}
		}
		for(int i=1;i<=n;++i){
			a[i]=(a[i]+a[i-1])%mod;
			b[i]=(b[i]+b[i-1])%mod;
			c[i]=(c[i]+c[i-1])%mod;
			cout<<((c[i]*(1ll*i*i)%mod+b[i]*i%mod+a[i])%mod+mod)%mod;
			if(i<n)cout<<" ";			
		}
		cout<<endl;
	}
	return 0;
}
