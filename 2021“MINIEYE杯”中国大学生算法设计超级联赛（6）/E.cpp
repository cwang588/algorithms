#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
int b[MAXN];
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int l, r;
        int n, m; scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        sort(b + 1, b + m + 1);
        l = r = 0;
        for(int i = m; i >= 1; i--)
        {
            int mi;
            if(i == m) mi = n-b[i];
            else mi = b[i+1]-b[i]-1;
            int Max = r + mi, Min;
            if(l == r)
            {
                if(l == mi) Min = 0;
                else if(mi < l) Min = l-mi-1;
                else Min = mi-l-1;
            }else
            {
                if(l <= mi && mi <= r) Min = 0;
                else if(mi < l) Min = l-mi-1;
                else Min = mi-r-1;
            }
            l = Min, r = Max;
        }
        int t = b[1]-1;
        if(l <= t && t <= r) puts("YES"); else puts("NO");
    }
    return 0;
}
