#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int a[100005],b[100005],d[100005],col[100005],pos[100005];
bool usd[100005];
long long qpow(long long a,long long b){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],pos[a[i]]=i;
		for(int i=1;i<=n;++i)cin>>b[i];
		for(int i=1;i<=n;++i)cin>>d[i];
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(!col[i]){
				++cnt;
				int now=i;
				while(!col[now]){
					col[now]=cnt;
					now=pos[b[now]];
				}
			}
		}
		long long ans=qpow(2,cnt),inv=qpow(2,mod-2);
		for(int i=1;i<=n;++i){
			if(a[i]==b[i]){
				ans=ans*inv%mod;
				continue;
			}
			if(!d[i])continue;	
			if(!usd[col[i]]){
				ans=ans*inv%mod;
				usd[col[i]]=true;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)col[i]=usd[i]=0;
	}
	
	return 0;
}