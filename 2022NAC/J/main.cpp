#include <bits/stdc++.h>

using namespace std;
char a[4][4], tmp[4][4];

int judge(char c[][4]) {
    for (int i = 1; i <= 3; ++i) {
        if (c[i][1] && c[i][1] == c[i][2] && c[i][1] == c[i][3]) {
            return c[i][1] == 'X' ? 1 : -1;
        }
    }
    for (int i = 1; i <= 3; ++i) {
        if (c[1][i] && c[1][i] == c[2][i] && c[1][i] == c[3][i]) {
            return c[1][i] == 'X' ? 1 : -1;
        }
    }
    if (c[1][1] && c[1][1] == c[2][2] && c[1][1] == c[3][3]) {
        return c[1][1] == 'X' ? 1 : -1;
    }
    if (c[3][1] && c[3][1] == c[2][2] && c[3][1] == c[1][3]) {
        return c[3][1] == 'X' ? 1 : -1;
    }
    return 0;
}

long long dp[260005][2];

int calc(char c[][4]) {
    int re = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            int now;
            if (c[i][j] == 'X')now = 1;
            else if (c[i][j] == 'O')now = 2;
            else now = 0;
            re = re * 3 + now;
        }
    }
    return re;
}

bool usd[200005];

int dfs(int now) {
    int id = calc(tmp);
    if (usd[id])return id;
    usd[id] = true;
    int result = judge(tmp);
    if (result) {
        if (result == 1)dp[id][0] = 1;
        else dp[id][1] = 1;
        return id;
    }
    char cur = now ? 'O' : 'X';
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (!tmp[i][j]) {
                tmp[i][j] = cur;
                int to = dfs(now ^ 1);
                dp[id][0] += dp[to][0];
                dp[id][1] += dp[to][1];
                tmp[i][j] = 0;
            }
        }
    }
    return id;
}

int main() {
    dfs(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                cin >> a[i][j];
                if (a[i][j] == '.')a[i][j] = 0;
            }
        }
        int id = calc(a);
        if (!usd[id]) {
            cout << "-1 -1\n";
        } else {
            cout << dp[id][0] << " " << dp[id][1] << "\n";
        }
    }
    return 0;
}
