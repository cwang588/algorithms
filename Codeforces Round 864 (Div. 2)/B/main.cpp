#include <bits/stdc++.h>

using namespace std;
int a[1005][1005], n;

inline int calc(int x) {
    return n + 1 - x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)cin >> a[i][j];
        }
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = calc(i), y = calc(j);
                if (a[i][j] == a[x][y])++num1;
                else ++num2;
            }
        }
        if (n % 2) {
            for (int i = 1; i <= n / 2; ++i) {
                if (a[n / 2 + 1][i] == a[n / 2 + 1][calc(i)])++num1;
                else ++num2;
            }
        }
        if (num2 > k) {
            cout << "NO\n";
        } else {
            if(n%2)cout<<"YES\n";
            else {
                if ((k - num2) % 2)cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}
