#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

const int N = 15, M = 55, MAX = 500010;
int n, m, limit;
int a[M][N], f[MAX];

inline int read()
{
    char ch = getchar(); int x = 0, flag = 0;
    while (!isdigit(ch)){ if (ch == '-') flag = 1; ch = getchar(); }
    while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
    return flag ? -x : x;
}

int main()
{
    n = read(), m = read(), limit = read();
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) a[i][j] = read();
    for (int i = 2; i <= m; i ++){
        int Max = 0;
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j ++)
            for (int k = a[j][i-1]; k <= limit; k ++){
                f[k] = max(f[k], f[k-a[j][i-1]]+a[j][i]-a[j][i-1]);
                Max = max(Max, f[k]);
            }
        limit += Max;
    }
    printf("%d\n", limit);
    return 0;
}
