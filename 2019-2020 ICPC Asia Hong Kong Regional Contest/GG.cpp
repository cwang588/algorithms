#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#define SIZE 200005
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define mp make_pair
#define ll long long
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
int k, cnt;
int pa[SIZE], c[SIZE], tmp[SIZE];

int dfs(int k, int f) {
	int now = ++cnt;
	pa[now] = f;
	if (k <= 2) {
		pa[++cnt] = now;
		c[cnt] = tmp[now] = 1;
		c[now] = 3 - k;
		return 1;
	}
	tmp[now] = dfs(k / 2, now) + dfs(2, now);
	c[now] = tmp[now] + (k % 2 == 0);
	return tmp[now];
}

int main() {
	io(); cin >> k;
	dfs(k, 0);
	cout << cnt << '\n';
	rep(i, 2, cnt) cout << pa[i] << ' ';
	cout << '\n';
	rep(i, 1, cnt) cout << c[i] << ' ';
}
