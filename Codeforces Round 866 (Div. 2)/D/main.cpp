#include <bits/stdc++.h>

using namespace std;
unordered_map<long long, vector<int>> a, b;
long long x[200005], y[200005];
bool usd[200005];
int n;

bool check(long long reX, long long reY, int now) {
    while (reX > 0 && reY > 0) {
        if (!now) {
            bool changed = false;
            for (const auto &c: a[reX]) {
                if (!usd[c])reY -= y[c], usd[c] = true, changed = true;
            }
            if (!changed)return false;
        } else {
            bool changed = false;
            for (const auto &c: b[reY]) {
                if (!usd[c])reX -= x[c], usd[c] = true, changed = true;
            }
            if (!changed)return false;
        }
        if (reX < 0 || reY < 0)return false;
        now ^= 1;
    }
    if (reX < 0 || reY < 0)return false;
    for (int i = 1; i <= n; ++i)if (!usd[i])return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        a.clear(), b.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
            a[x[i]].push_back(i), b[y[i]].push_back(i);
        }
        set<pair<long long, long long>> ans;

        for (int i = 1; i <= n; ++i)usd[i] = false;
        long long MaxX = 0, MaxY = 0;
        for (int i = 1; i <= n; ++i)MaxX = max(MaxX, x[i]);
        long long totX = 0, totY = 0;
        for (const auto &c: a[MaxX]) {
            totY += y[c];
            usd[c] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (!usd[i])MaxY = max(MaxY, y[i]);
        }
        totY += MaxY;
        for (const auto &c: b[MaxY]) {
            if (!usd[c])totX += x[c];
            usd[c] = true;
        }
        if (check(MaxX - totX, MaxY, 0))ans.insert(make_pair(MaxX, totY));

        for (int i = 1; i <= n; ++i)usd[i] = false;

        MaxX = 0, MaxY = 0;
        for (int i = 1; i <= n; ++i)MaxY = max(MaxY, y[i]);
        totX = 0, totY = 0;
        for (const auto &c: b[MaxY]) {
            totX += x[c];
            usd[c] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (!usd[i])MaxX = max(MaxX, x[i]);
        }
        totX += MaxX;
        for (const auto &c: a[MaxX]) {
            if (!usd[c])totY += y[c];
            usd[c] = true;
        }
        if (check(MaxX, MaxY - totY, 1))ans.insert(make_pair(totX, MaxY));

        cout << ans.size() << "\n";
        for (const auto &p: ans)cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
