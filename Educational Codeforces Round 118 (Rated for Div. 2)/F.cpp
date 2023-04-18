#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
int num[250005];
const ll mod = (119 << 23) + 1, root = 62;
typedef vector<ll> vl;
queue<vl>q1,q2;
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
	if (e & 1) ans = ans * b % mod;
	return ans;
}
void ntt(vl& a, vl& rt, vl& rev, int n) {
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty())
	return {};
	int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
	vl L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n); ntt(R, rt, rev, n);
	rep(i,0,n) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}
vl getnext(){
	if(q1.empty()){
		vl re=q2.front();
		q2.pop();
		return re;
	}
	if(q2.empty()){
		vl re=q1.front();
		q1.pop();
		return re;
	}
	if(q1.front().size()<=q2.front().size()){
		vl re=q1.front();
		q1.pop();
		return re;
	}
	else{
		vl re=q2.front();
		q2.pop();
		return re;
	}
}
ll inv[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	inv[0]=1;
	for(int i=1;i<=250000;++i)inv[i]=inv[i-1]*i%mod;
	int n;
	cin>>n;
	for(int i=2;i<=n;++i){
		int x,y;
		cin>>x>>y;
		++num[x],++num[y],--num[i];
	}	
	for(int i=1;i<=n;++i){
		vl tmp;
		tmp.push_back(1);
		tmp.push_back(num[i]);
		q1.push(tmp);
	}
	for(int i=1;i<n;++i){
		vl tmp1=getnext(),tmp2=getnext();
		q2.push(conv(tmp1,tmp2));
	}
	ll ans=0;
	vl f=q2.front();
	for(int i=0;i<n;++i)ans=(ans+(i%2?-1:1)*inv[n-i]*f[i])%mod;
	cout<<(ans+mod)%mod;
	return 0;
}