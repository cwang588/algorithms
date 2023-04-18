#include <bits/stdc++.h>

using namespace std;
char a[50005][7];

int getId(int x, int y, int z) {
    return x * 26 * 26 + y * 26 + z;
}

int main() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                int now = getId(i, j, k) * 2;
                a[now][0] = a[now][1] = (char) ('a' + i);
                a[now][2] = a[now][3] = (char) (i % 2 == 0 ? 'a' + j : 'z' - j);
                int jj = i % 2 == 0 ? j : 25 - j;
                a[now][4] = a[now][5] = (char) ((i + jj) % 2 == 0 ? 'a' + k : 'z' - k);
                if (now) {
                    bool usd = false;
                    for (int o = 0; o < 6; ++o) {
                        if (a[now][o] != a[now - 2][o] && !usd) {
                            a[now - 1][o] = a[now - 2][o];
                            usd = true;
                        } else {
                            a[now - 1][o] = a[now][o];
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5000; ++i) {
        for (int j = i + 2; j < 5000; ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k)if (a[i][k] != a[j][k])++cnt;
            if (cnt <= 1) {
                cout << i << ":" << a[i] << " " << j << ":" << a[j] << "\n";
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)cout << a[i] << "\n";
    return 0;
}
