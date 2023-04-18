#include<bits/stdc++.h>
using namespace std;
const int mxn = 2e5;
int sz[mxn];
int main()
{
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        if (x * y < n || x + y > n + 1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int rmn = n;
        for (int i = 0; i < x - 1; ++i)
            sz[i] = 1, --rmn;
        sz[x - 1] = y, rmn -= y;
        for (int i = x - 2; i >= 0 && rmn > 0; --i)
        {
            int dif = min(rmn, y - sz[i]);
            sz[i] += dif, rmn -= dif;
        }
        vector<int> ans;
        for (int i = 0; i < x; ++i)
        {
            int l = ans.size(), r = l + sz[i];
            for (int j = r; j > l; --j)
                ans.push_back(j);
        }
        for (int i = 0; i < n; ++i)
            printf(i ? " %d" : "%d", ans[i]);
        printf("\n");
    }
    return 0;
}
