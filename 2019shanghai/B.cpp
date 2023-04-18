#include <bits/stdc++.h>
using namespace std;
string code[10005];
bool isprefix(int a, int b) {
	if (code[a].length() > code[b].length()) return false;
	for (int i = 0; i < code[a].size() && i < code[b].size(); ++i) {
		if (code[a][i] < code[b][i]) return false;
	}
	return true;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> code[i];
		}
		sort(code + 1, code + n + 1);
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (isprefix(i, i + 1)) {
				ok = false;
			}
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}