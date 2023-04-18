#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];
bool vis[MAXN];
int p[30], v[30], tot;
LL dfs(int i, LL k) {
    if (i > tot) return k;
    LL res = dfs(i + 1, k); // 不取第i个 
    k += a[p[i]];
    k -= 1LL * v[i] * b[p[i]];
    for (int j = i; j <= tot; j += i) v[j] ++;
    res = max(res, dfs(i + 1, k)); // 取第i个 
    for (int j = i; j <= tot; j += i) v[j] --;
    return res; 
}
int main() 
{
    int n,A; scanf("%d%d", &n,&A);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    LL res = a[1]>0?a[1]:0;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        tot =  0;
        for (LL j = i; j <= n; j *= i) {
            p[++tot] = j;
            vis[j] = true;
        }
        res += dfs(1, 0);
    }
    printf("%lld\n", res+A);
    return 0;
}
