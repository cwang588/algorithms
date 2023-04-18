#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n, m;

int a[MAXN], cnt, dfn[MAXN], sz[MAXN];
vector<int> e[MAXN];
int f[MAXN][20];
pair<pair<int, int>, int> q[MAXN];
pair<int, int> b[MAXN];

void dfs(int x, int fa) {
    dfn[x] = ++cnt;
    sz[x] = 1;
    for (auto v : e[x]) {
        if (v == fa) continue;
        f[v][0] = x;;
        dfs(v, x);
        sz[x] += sz[v];
    }
}

int tr[MAXN], ans[MAXN];

void Add(int x, int y) {
    for (; x <= n; x += x & -x) tr[x] += y;
}

int Ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += tr[x];
    return ans;
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second > b.first.second;
}

int main() {
	freopen("in.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) b[i] = make_pair(a[i], i);
    dfs(1, 0);
    for (int j = 0; j <= 18; j++)
        for (int i = 1; i <= n; i++) f[i][j + 1] = f[f[i][j]][j];
    scanf("%d", &m);
    a[0] = 1e9 + 1;
    int tot = 0;
    for (int i = 1; i <= m; i++) {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (a[x] > r || a[x] < l) {
            ans[i] = 0;
            continue;
        }
        for (int j = 18; j >= 0; j--) if (a[f[x][j]] <= r) x = f[x][j];
        q[++tot] = make_pair(make_pair(x, l), i);
    }
    sort(q + 1, q + tot + 1, cmp);
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    for (int i = 1, j = 1; i <= tot; i++) {
        while (j <= n && b[j].first >= q[i].first.second) {
            Add(dfn[b[j].second], 1);
            j++;
        }
        int id = q[i].second;
        int l = dfn[q[i].first.first], r;
        r = l + sz[q[i].first.first] - 1;
        ans[id] = Ask(r) - Ask(l - 1);
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
