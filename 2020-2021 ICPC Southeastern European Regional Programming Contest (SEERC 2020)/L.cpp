#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const long long MOD=1000000007;
vi sons[1000005];
ll dp1[1000005], dp2[1000005];
int main()
{
	ll n;
	cin >> n;
	for (ll i = 3; i <= n; ++i) {
		for (ll j = 1; i * j <= n; ++j) {
			sons[i * j].push_back(i);
			sons[i * j + 1].push_back(i);
			sons[i * j + 2].push_back(i);
		}
	}
	dp1[3] = 1, dp1[4] = 1;
	for (int i = 5; i <= n; ++i) {
		dp1[i] = 1;
		for (auto s : sons[i]) {
			if (s == i || s == i - 1) continue;
			//cout << i << ": " << s << endl;
			dp1[i] = (dp1[i] + dp1[s + 1]) % MOD;
		}
		//cout << dp[i] << endl;
	}
	for (int i = 3; i <= n; ++i) {
		dp2[i] = (dp2[i - 1] + dp1[i]) % MOD;	
	}
	if(n == 1) cout << "1\n";
	else if(n == 2) cout << "2\n";
	else cout << dp2[n] * n * 2 % MOD << endl;
	return 0;
}

