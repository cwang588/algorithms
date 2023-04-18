#include <bits/stdc++.h>
using namespace std;
int x[55], c[55], col[55];
vector<int> d;
unordered_set<int> mp;
bool judge(int t){
	for(int i=1;i)
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (c[i] != c[j]) {
                d.push_back(abs(x[i] - x[j]));
            }
        }
    }
    for (auto dis : d) {
        for (int i = 1; i * i <= 2000000001; ++i) {
            if (dis % i == 0) {
                mp.insert(i);
                if (i != dis / i) {
                    mp.insert(dis / i);
                }
            }
        }
    }
    for (int t = 1; t <= 50; ++t) {
        for (int i = 0; i < t; ++i) col[i] = -1;
        for (int i = 1; i <= n; ++i) {
            if (col[((x[i] % t) + t) % t] != -1 && col[((x[i] % t) + t) % t] != c[i]) {
                // cout << "not eq\n" << t << '\n';
                mp.insert(t);
                break;
            }
            col[((x[i] % t) + t) % t] = c[i];
        }
        bool ok = false;
        for (int i = 0; i < t; ++i) {
            if (col[i] == -1) {
                ok = true;
                break;
            }
        }
        if (!ok && t != 1 && judge()) mp.insert(t);
    }
    cout << mp.size() << ' ';
    long long sum = 0;
    for (auto val : mp) {
        sum += val;
    }
    cout << sum << '\n';
    return 0;
}