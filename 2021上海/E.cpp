#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
	int n, k, a;
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	a = vec[0];
	int ans = 1;
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] - a >= k) {
			ans++;
			a = vec[i];
		}
	}
	cout << ans << '\n';
	return 0;
}