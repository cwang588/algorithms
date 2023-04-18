#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s += s;
        int n = s.length(), Max = 0, now = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')++now;
            else now = 0;
            Max = max(Max, now);
        }
        if (Max == n) {
            cout << 1ll * (n / 2) * (n / 2) << "\n";
        } else {
            long long ans = 0;
            for (int i = 1; i <= Max; ++i)ans = max(ans, 1ll * i * (Max + 1 - i));
            cout << ans << "\n";
        }
    }
    return 0;
}
