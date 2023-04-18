#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i, x, y) for (REG int i = (x); i < (y); i++)
#define DRPT(i, x, y) for (REG int i = (x); i > (y); i--)
#define MST(a, b) memset((a), (b), sizeof(a))
#define MRK() cout << "Mark" << endl;
#define WRT(x) cout << #x << " = " << (x) << endl;

#define MAXN 310000
#define MAXM 610000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
int n, x, y;
LL sum[MAXN];
LL ans;

void dfs(int pos, int f) {
    sum[pos] = pos;
    ans += (LL)pos * pos % MOD * pos % MOD;
    for (auto p : g[pos])
        if (p != f) {
            dfs(p, pos);
            ans += (LL)sum[p] * sum[pos] % MOD * pos % MOD * 2 % MOD;
            sum[pos] = (sum[pos] + sum[p]) % MOD;
        }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    cout << ans % MOD;
    return ~~(0 ^ _ ^ 0);
}
