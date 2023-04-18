#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
pair<int,int>op[200005];
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
bool usdx[200005],usdy[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,q;
		cin>>n>>m>>k>>q;
		for(int i=1;i<=q;++i)cin>>op[i].first>>op[i].second;
		int numx=0,numy=0;
		long long cnt=0;
		for(int i=q;i>=1;--i){
			if(!usdx[op[i].first]||!usdy[op[i].second])++cnt;
			if(!usdx[op[i].first])usdx[op[i].first]=true,++numx;
			if(!usdy[op[i].second])usdy[op[i].second]=true,++numy;
			if(numx==n||numy==m)break;
		}
		cout<<quickpower(k,cnt,mod)<<"\n";
		for(int i=1;i<=q;++i)usdx[op[i].first]=usdy[op[i].second]=false;
	}
	
	
	return 0;
}