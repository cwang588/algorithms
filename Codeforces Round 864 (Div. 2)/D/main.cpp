#include <bits/stdc++.h>

using namespace std;
struct edge {
    int from, to, nxt;
} e[200005];
int cnt, Head[100005];

void add(int x, int y) {
    ++cnt;
    e[cnt].from = x;
    e[cnt].to = y;
    e[cnt].nxt = Head[x];
    Head[x] = cnt;
}

long long value[100005], tot[100005];
int fa[100005], sz[100005];
set<pair<int, int> > son[100005];

void dfs(int now, int pre) {
    sz[now] = 1;
    fa[now] = pre;
    tot[now] = value[now];
    for (int i = Head[now]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == pre)continue;
        dfs(to, now);
        sz[now] += sz[to];
        tot[now] += tot[to];
        son[now].insert(make_pair(-sz[to], to));
    }
}

int getSon(int x) {
    if (son[x].empty())return 0;
    return son[x].begin()->second;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)cin >> value[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 2) {
            if (son[y].empty())continue;
            int yy = getSon(y);
            if (fa[y]) {
                son[fa[y]].erase(make_pair(-sz[y], y));
                son[fa[y]].insert(make_pair(-sz[y], yy));
            }
            son[y].erase(make_pair(-sz[yy], yy));
            int tmp = sz[yy];
            sz[yy] = sz[y], sz[y] -= tmp;
            son[yy].insert(make_pair(-sz[y], y));
            fa[yy] = fa[y], fa[y] = yy;
            long long tmp_tot = tot[y];
            tot[y] -= tot[yy], tot[yy] = tmp_tot;
        } else {
            cout << tot[y] << "\n";
        }
    }
    return 0;
}
