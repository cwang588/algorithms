#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#define SIZE 5005
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define mp make_pair
#define ll long long
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
const int maxn = 2e5;
ll t, n, a[SIZE];

bool check(int pos) {
	int dif = abs(a[pos] - (n + 1) / 2);
	int f = (a[pos] < (n + 1) / 2);
	int now = 0, num = 0;
	rep(i, 1, n) {
		if (i == pos) { now = 0; continue; }
		int ff = (a[i] < a[pos]);
		if (f == ff) now = max(now - 1, 0);
		else {
			++now;
			if (now == 3) ++num, now -= 2;
		}
	}
	return num >= dif;
}

int main() {
	//io(); 
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) {
			if (check(i)) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
}
