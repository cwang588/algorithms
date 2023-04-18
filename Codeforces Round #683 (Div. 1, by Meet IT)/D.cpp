#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005, N = 305;
int sum[N][maxn], a[maxn], mul[N][N], cc[N][N];
int tmp[maxn];
//sum[i][j]统计前i块数字j出现的次数
//mul[i][j]计算众数个数最多且数字最少的数
//cc[i][j]计算众数最多个数
void solve ( )
{
    int n, Q;
    //freopen ( "in0.in", "r", stdin );
    //freopen ( "in1.out", "w", stdout );
    scanf ( "%d%d", &n, &Q );
    for ( int i = 0; i < n; i ++ )
        scanf ( "%d", &a[i] );
    int blo = ( int )sqrt ( n )+1;
    int cnt = ( n+blo-1 )/blo;
    for ( int i = 1; i <= blo; i ++ )
    {
        for ( int j = 0; j < n; j ++ )
            sum[i][j] = sum[i-1][j];
        for ( int j = ( i-1 )*cnt; j < n && j < i*cnt; j ++ )
            sum[i][ a[j] ] ++;
    }
    for ( int i = 1; i <= blo; i ++ )
    {
        for ( int j = i; j <= blo; j ++ )
        {
            cc[i][j] = cc[i][j-1];	//注意初始化
            mul[i][j] = mul[i][j-1];
            for ( int k = ( j-1 )*cnt; k < n && k < j*cnt; k ++ )
            {
                int x = sum[j][ a[k] ]-sum[i-1][ a[k] ];
                if ( x > cc[i][j] || x == cc[i][j] && mul[i][j] > a[k] )
                {
                    cc[i][j] = x;
                    mul[i][j] = a[k];
                }
            }
        }
    }
    int L, R, ans, anspos;
    //ans次数最多，anspos次数最多且数字最小
    while ( Q -- )
    {
        scanf ( "%d%d", &L, &R );
        int x = L/cnt+1, y = R/cnt+1;
        ans = cc[x+1][y-1], anspos = mul[x+1][y-1];
        for ( int i = L; i <= R && i < x*cnt; i ++ )
            tmp[ a[i] ] = max ( 0, sum[y-1][ a[i] ]-sum[x][ a[i] ] );
        for ( int i = max ( L, ( y-1 )*cnt ); i <= R; i ++ )
            tmp[ a[i] ] = max ( 0, sum[y-1][ a[i] ]-sum[x][ a[i] ] );
        for ( int i = L; i < x*cnt && i <= R; i ++ )
        {
            tmp[ a[i] ] ++;
            if ( tmp[ a[i] ] > ans || tmp[ a[i] ] == ans && a[i] < anspos )
            {
                ans = tmp[ a[i] ];
                anspos = a[i];
            }
        }
        if ( x != y )	//同块处理
        {
            for ( int i = ( y-1 )*cnt; i <= R; i ++ )
            {
                tmp[ a[i] ] ++;
                if ( tmp[ a[i] ] > ans || tmp[ a[i] ] == ans && a[i] < anspos )
                {
                    ans = tmp[ a[i] ];
                    anspos = a[i];
                }
            }
        }
        printf ( "%d %d\n", anspos, ans );
    }
}
int main ( )
{
    solve ( );
    return 0;
}
