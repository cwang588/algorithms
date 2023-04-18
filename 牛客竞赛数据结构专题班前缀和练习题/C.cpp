#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod=998244353,root=62;
typedef vector<ll> vl;
ll modpow(ll b,ll e){
	ll ans=1;
	for(;e;b=b*b%mod,e/=2)
		if(e&1)ans=ans*b%mod;
	return ans;
}
void ntt(vl& a,vl& rt,vl& rev,int n){
	rep(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int k=1;k<n;k*=2){
		for(int i=0;i<n;i+=2*k)rep(j,0,k){
			ll z=rt[j+k]*a[i+j+k]%mod,&ai=a[i+j];
			a[i+j+k]=(z>ai?ai-z+mod:ai-z);
			ai+=(ai+z>=mod?z-mod:z);
		}
	}
}
vl conv(const vl& a,const vl& b){
	if(a.empty()||b.empty())return {};
	int s=sz(a)+sz(b)-1,B=32-__builtin_clz(s),n=1<<B;
	vl L(a),R(b),out(n),rt(n,1),rev(n);
	L.resize(n),R.resize(n);
	rep(i,0,n)rev[i]=(rev[i/2]|(i&1)<<B)/2;
	ll curL=mod/2,inv=modpow(n,mod-2);
	for(int k=2;k<n;k*=2){
		ll z[]={1,modpow(root,curL/=2)};
		rep(i,k,2*k)rt[i]=rt[i/2]*z[i&1]%mod;
	}
	ntt(L,rt,rev,n);ntt(R,rt,rev,n);
	rep(i,0,n)out[-i&(n-1)]=L[i]*R[i]%mod*inv%mod;
	ntt(out,rt,rev,n);
	return {out.begin(),out.begin()+s};
}
int main(){
	int n;
	long long k;	
	cin>>n>>k;
	vl a;
	for(int i=1;i<=n;++i){
		long long tmp;
		cin>>tmp,a.push_back(tmp);
	}
	if(k==0){
		for(auto x:a)cout<<x<<" ";
		cout<<"\n";
	}
	else if(k>0){
		vl b;
		b.push_back(1);
		long long now=1;
		for(int i=1;i<=n;++i){
			now=(k+i-1)%mod*now%mod*modpow(i,mod-2)%mod;
			b.push_back(now);
		}
		auto ans=conv(a,b);
		for(int i=0;i<n;++i)cout<<(ans[i]%mod+mod)%mod<<" ";
		cout<<"\n";
	}
	else{
		vl b;
		b.push_back(1);
		long long now=1;
		for(int i=1;i<=n;++i){
			now=(-k-i+1)%mod*now%mod*modpow(i,mod-2)%mod*(-1)%mod;
			b.push_back(now);
		}
		auto ans=conv(a,b);
		for(int i=0;i<n;++i)cout<<(ans[i]%mod+mod)%mod<<" ";
		cout<<"\n";
	}
	return 0;
}