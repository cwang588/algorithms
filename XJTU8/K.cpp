#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+7;
ll len[MAXN];
char s[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for(int Case = 1; Case <= T; Case++)
    {
        int sum = 0;
        cin >> s;
        int i = 0, pre = -1;
        while(i < strlen(s))
        {
            int t = s[i] - '0';
            if(t != pre)
            {
                len[++sum] = 1;
            }else len[sum]++;
            pre = t;
            i++;
        }
        ll ans = 0, Maxx = 0;
        for(int i = 1; i <= sum; i++) ans += len[i] * len[i];
        len[sum + 1] = 0, len[0] = 0;
        for(int i = 1; i < sum; i++)
        {
            ll a = len[i-1], b = len[i], c = len[i+1], d = len[i+2];
            if(b > 1)
            {
                Maxx = max(Maxx, ((c + 1) * (c + 1)) - (c * c)
                + ((b - 1) * (b - 1)) - (b * b));
            }else
            {
                Maxx = max(Maxx, ((a + b + c) * (a + b + c))
                - (a * a) - (b * b) - (c * c));
            }
            if(len[i+1] == 1)
            {
                Maxx = max(Maxx, ((b + c + d) * (b + c + d))
                - (b * b) - (c * c) - (d * d));
            }else
            {
                Maxx = max(Maxx, ((b + 1) * (b + 1)) - (b * b)
                + ((c - 1) * (c - 1)) - (c * c));
            }
        }
        ans += Maxx;
        cout << "Case #" << Case << ": " << ans << endl;
    }
//    system("pause");
}
