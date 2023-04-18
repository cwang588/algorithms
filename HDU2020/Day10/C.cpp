#include<bits/stdc++.h>
using namespace std;
string mp[30];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int s;
        scanf("%d", &s);
        if (s == 0)
            printf("1 1\n.\n");
        else if (s == 1)
            printf("1 2\nX.\n");
        else if (s == 2)
            printf("1 3\n.X.\n");
        else if (s == 4)
            printf("2 2\n.X\nX.\n");
        else if (s == 7)
            printf("2 4\nX..X\nX...\n");
        else
        {
            printf("25 25\n");
            for (int i = 0; i < 25; ++i)
                mp[i] = ".........................";
            if (s < 38)
            {
                int x, y;
                for (int i = 0; i < s; ++i)
                    if ((s - 5 * i) % 3 == 0)
                    {
                        x = i, y = (s - 5 * i) / 3;
                        break;
                    }
                for (int i = 0; i < x; ++i)
                    mp[0][2 * i + 1] = 'X';
                for (int i = 0; i < y; ++i)
                    mp[24][i] = 'X';
            }
            else
            {
                int l = s / 140, r = s % 140, e = 0, n = 0;
                if (r >= 8)
                    ++e, r -= 8;
                while (e && r >= 6)
                    ++n, r -= 6;
                for (int i = 0; i < l; ++i)
                    for (int j = 1; j < 24; ++j)
                        mp[2 * i + 1][j] = 'X';
                for (int i = 1; i <= e + n; ++i)
                    mp[2 * l + 1][i] = 'X';
                for (int i = 0; i < r; ++i)
                    mp[1][i + 1] = '.',
                    mp[24][2 * i + 1] = 'X';
            }
            for (int i = 0; i < 25; ++i)
                cout << mp[i] << "\n";
        }
    }
    return 0;
}

