#include <bits/stdc++.h>

using namespace std;
struct edge {
    int from, to, nxt;
} e[10005];
int cnt, Head[5005];

void add(int x, int y) {
    ++cnt;
    e[cnt].from = x;
    e[cnt].to = y;
    e[cnt].nxt = Head[x];
    Head[x] = cnt;
}

int value[5005], dp[5005][105];
vector<int> num, prime;
vector<vector<int>> p;

int getId(int x) {
    return lower_bound(prime.begin(), prime.end(), x) - prime.begin();
}

int tmp[5005][2005];

void dfs(int now, int pre) {
    for (int i = 0; i < prime.size(); ++i) {
        dp[now][i] = 100000000;
    }
    for (int i = 0; i < num.size(); ++i) {
        tmp[now][i] = (num[i] == value[now] ? 0 : num[i]);
    }
    for (int i = Head[now]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == pre)continue;
        dfs(to, now);
        for (int j = 0; j < num.size(); ++j) {
            int Min = 100000000;
            for (const auto &x: p[j]) {
                Min = min(Min, dp[to][getId(x)]);
            }
            tmp[now][j] += Min;
        }
    }
    for (int i = 0; i < num.size(); ++i) {
        for (const auto &x: p[i]) {
            dp[now][getId(x)] = min(dp[now][getId(x)], tmp[now][i]);
        }
    }
}

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

bool check(int x) {
    for (int i = 2; i <= 100; ++i) {
        int num_cnt = 0;
        while (x % i == 0) {
            x /= i;
            ++num_cnt;
        }
        if (num_cnt > 1)return false;
    }
    return x == 1;
}

vector<int> divide(int x) {
    vector<int> re;
    for (int i = 2; i <= 100; ++i) {
        if (x % i == 0) {
            while (x % i == 0)x /= i;
            re.push_back(i);
        }
    }
    return re;
}

void init() {
    for (int i = 2; i <= 100; ++i) {
        num.push_back(i);
        p.push_back(divide(i));
    }
    for (int i = 101; i <= 10000; ++i) {
        if (check(i)) {
            num.push_back(i);
            p.push_back(divide(i));
        }
    }
    for (int i = 2; i <= 100; ++i) {
        bool ky = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ky = false;
                break;
            }
        }
        if (ky)prime.push_back(i);
    }
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> value[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int ans = 2147483647;
    for (int i = 0; i < prime.size(); ++i)ans = min(ans, dp[1][i]);
    cout << ans << "\n";
    return 0;
}
