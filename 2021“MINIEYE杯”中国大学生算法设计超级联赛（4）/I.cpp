#include<bits/stdc++.h>
using namespace std;
string s[40];
int l[20], r[20];
int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d:\n", t);
        for(int i = 1; i <= 30; i++) cin >> s[i];
        int pre = 0, cnt = 0;
        for(int j = 0; j < 100; j++)
        {
            int now = 0;
            for(int i = 1; i <= 30; i++)
                if(s[i][j] == '#') now = 1;
            if(!pre && now) l[++cnt] = j+1;
            if(pre && !now) r[cnt] = j;
            pre = now;
        }
        if(cnt == 9)
        {
            printf("%d %d\n", l[1], r[3]);
            for(int i = 4; i <= 9; i++)
                printf("%d %d\n", l[i], r[i]);
        }else
            for(int i = 1; i <= 7; i++)
                printf("%d %d\n", l[i], r[i]);
    }
//    system("pause");
}
