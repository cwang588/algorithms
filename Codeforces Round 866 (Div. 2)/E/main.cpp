#include <bits/stdc++.h>

using namespace std;
vector<int> to[200005];
int dis, pos;

void dfs(int now, int pre, int dep) {
    if (dep > dis) {
        dis = dep;
        pos = now;
    }
    for (const auto &x: to[now]) {
        if (x == pre)continue;
        dfs(x, now, dep + 1);
    }
}

bool usd[200005];

bool dfs2(int now, int pre, int target) {
    if (now == target) {
        usd[now] = true;
        return true;
    }
    for (const auto &x: to[now]) {
        if (x == pre)continue;
        if (dfs2(x, now, target)) {
            usd[now] = true;
            return true;
        }
    }
    return false;
}

int gap[200005];

void dfs3(int now, int pre) {
    if (!usd[now])gap[now] = gap[pre] + 1;
    for (const auto &x: to[now]) {
        if (x == pre)continue;
        dfs3(x, now);
    }
}

vector<vector<int>> points;

void dfs4(int now, int pre) {
    points.push_back({now});
    int next = 0;
    for (const auto &x: to[now]) {
        if (x == pre)continue;
        if (usd[x])next = x;
        else points.back().push_back(x);
    }
    if (next)dfs4(next, now);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y), to[y].push_back(x);
    }
    dfs(1, 0, 0);
    int pos2 = pos;
    dis = 0;
    dfs(pos, 0, 0);
    dfs2(pos, 0, pos2);
    dfs3(pos, 0);
    bool ky = true;
    for (int i = 1; i <= n; ++i) {
        if (gap[i] > 1) {
            ky = false;
            break;
        }
    }
    if (!ky) {
        cout << "No\n";
        return 0;
    }
    dfs4(pos, 0);
    cout << "Yes\n";
    int m = points.size();
    for (int i = 0; i < m; i += 2) {
        cout << points[i][0] << " ";
        int next = i + 1;
        if (next < m) {
            int sz = points[next].size();
            for (int j = 1; j < sz; ++j)cout << points[next][j] << " ";
        }
    }
    for (int i = (m - 1) % 2 ? (m - 1) : (m - 2); i >= 1; i -= 2) {
        cout << points[i][0] << " ";
        int next = i - 1;
        if (next >= 0) {
            int sz = points[next].size();
            for (int j = 1; j < sz; ++j)cout << points[next][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}
