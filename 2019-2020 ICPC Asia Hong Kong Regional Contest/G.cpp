#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
int tot, n, k, c[MAXN], f[MAXN], d[MAXN];
struct node
{
    int u, v;
}edge[MAXN];
void add(int u, int v) { edge[++tot].u = u, edge[tot].v = v; }
int dfs(int k, int u)
{
    if(k == 1) { c[n] = d[n] = 1; return 1; }
    if(k & 1)
    {
        n++, c[n] = 1, f[n] = u;
        n++, c[n] = 1, f[n] = n - 1;
        n++;
        f[n] = u;
        c[u] = 1 + dfs(k / 2, n);
        d[u] = c[u];
    }else
    {
        n++, c[n] = 1, f[n] = u;
        n++, c[n] = 1, f[n] = n - 1;
        n++;
        f[n] = u;
        c[u] = 2 + dfs(k / 2, n);
        d[u] = c[u] - 1;
    }
    return d[u];
}
int main()
{
    scanf("%d", &k);
    n = 1;
    dfs(k, 1);
    printf("%d\n", n);
    for(int i = 2; i < n; i++) printf("%d ", f[i]); printf("%d\n", f[n]);
    for(int i = 1; i < n; i++) printf("%d ", c[i]); printf("%d\n", c[n]);
//    system("pause");
}

