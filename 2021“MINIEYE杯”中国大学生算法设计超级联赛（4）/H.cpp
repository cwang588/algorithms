#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
struct node
{
    int x, y;
    bool operator<(const node &t)const { if(x == t.x) return y < t.y;  return x < t.x; }
}black[MAXN];
vector<int> bl[MAXN], br[MAXN], wl[MAXN], wr[MAXN];
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        long long ans = 0;
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= k; i++)
            scanf("%d%d", &black[i].x, &black[i].y);
        sort(black+1, black+k+1);
        int l, r;
        for(int i = 1; i <= k; i++)
        {
            if(!(black[i-1].x == black[i].x && black[i-1].y+1 == black[i].y))
            {
                bl[black[i].x].push_back(black[i].y);
                if(i > 1) br[black[i-1].x].push_back(black[i-1].y);
            }
        }
        br[black[k].x].push_back(black[k].y);
        for(int i = 1; i <= n; i++) bl[i].push_back(m+1), br[i].push_back(m+1);
        wl[1].push_back(1); wr[1].push_back(bl[1][0]-1);
        ans += wr[1][0]-wl[1][0]+1;
        for(int i = 2; i <= n; i++)
        {
            if(wl[i-1][0] < bl[i][0]) wl[i].push_back(wl[i-1][0]), wr[i].push_back(bl[i][0]-1),
            ans += bl[i][0]-wl[i-1][0];
            for(int j = 0; j < bl[i].size()-1; j++)
            {
                int t1 = upper_bound(wr[i-1].begin(), wr[i-1].end(), br[i][j])-wr[i-1].begin();
                if(t1 < wr[i-1].size() && wl[i-1][t1] < bl[i][j+1])
                {
                    wl[i].push_back(max(wl[i-1][t1], br[i][j]+1)), 
                    wr[i].push_back(bl[i][j+1]-1);
                    ans += bl[i][j+1]-max(wl[i-1][t1], br[i][j]+1);
                }
            }
        }
        printf("%lld\n", ans);
        /*
        for(int i = 1; i <= n; i++)
        {
            printf("%d:\n", i);
            for(int j = 0; j < wl[i].size(); j++)
            {
                printf("%d %d\n", wl[i][j], wr[i][j]);
            }
            puts("");
        }*/
        //system("pause");
    }
}
