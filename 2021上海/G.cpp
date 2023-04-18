#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll maxn = 100005;
ll dp[maxn], sz[maxn];
vector<int> G[maxn];
ll C_fac[maxn];
void dfssz(int u, int fa) {
	sz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfssz(v, u);
		sz[u] += sz[v];
	}
}
ll dfs(int u, int fa) {
	ll ans = 0;
	dp[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		ll ret = dfs(v, u);
		dp[u] = dp[u] * dp[v] % MOD;
		if (sz[v] & 1) {
			// ok not to choose u->v
			ans++;
		} else {
			// must choose u->v
			dp[u] = dp[u] * ret % MOD;
		}
	}
	dp[u] = dp[u] * C_fac[(ans >> 1) << 1] % MOD;
	return ans;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	C_fac[0] = 1;
	for (ll i = 2; i <= 100000; i += 2) {
		C_fac[i] = (C_fac[i - 2] * (i - 1)) % MOD;
	}
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfssz(1, -1);
	dfs(1, -1);
	cout << dp[1] << '\n';
	return 0;
}