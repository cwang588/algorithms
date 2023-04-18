#include <bits/stdc++.h>

using namespace std;
int a[200005];
map<int, int> usd;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        usd.clear();
        for (int i = 1; i <= n; ++i)cin >> a[i];
        int m = 0;
        for (int i = 1; i <= n; ++i)++usd[a[i]];
        for (int i = 0; i <= n; ++i) {
            if (!usd[i]) {
                m = i;
                break;
            }
        }
        if (!usd[m + 1]) {
            bool ky = false;
            for (int i = 1; i <= n; ++i) {
                if (a[i] > m || usd[a[i]] > 1) {
                    ky = true;
                    break;
                }
            }
            if (ky)cout << "Yes\n";
            else cout << "No\n";
        } else {
            int l = n + 1, r = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == m + 1) {
                    l = min(l, i), r = max(r, i);
                }
            }
            usd.clear();
            for (int i = 1; i < l; ++i)++usd[a[i]];
            for (int i = r + 1; i <= n; ++i)++usd[a[i]];
            int mm = 0;
            for (int i = 0; i <= n; ++i) {
                if (!usd[i]) {
                    mm = i;
                    break;
                }
            }
            if (mm < m)cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}
