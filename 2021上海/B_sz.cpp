#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll MOD = 998244353;
ll cnt[maxn];
vl div_conq(ll l, ll r) {
	ll mid = (l + r) >> 1;
	div_conq(l, mid);
	div_conq(mid + 1, r);
	vpl consts = get_con(l, r);
	for (auto p : consts)
}
int main()
{
	return 0;
}