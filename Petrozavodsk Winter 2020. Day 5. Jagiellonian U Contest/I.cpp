#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
vector<string> v;
string one;
string sub(string a, string b) {
    reverse(all(a));
    reverse(all(b));
    string ret;
    int len = max(a.length(), b.length()), carry = 0;
    for (int i = 0; i < len; ++i) {
        int dig = a[i] - carry - b[i];
        if (dig >= 0) {
            ret += dig + '0';
            carry = 0;
        } else {
            ret += dig + 10 + '0';
            carry = 1;
        }
    }
    for (int i = len - 1; i > 0; --i) {
        if (ret[i] == '0') ret.pop_back();
        else break;
    }
    reverse(all(ret));
    return ret;
}
bool zero(string &s) {
    return (s.length() == 1 && s[0] == '0');
}
void solve(string s, int lev) {
    if (zero(s)) return;
    int len = s.length();
    if (len == 1) {
        cout << s << '\n';
        return;
    }
    int halflen = len / 2;
    if (len & 1) {
        string pre, suf;
        for (int i = 0; i <= halflen; ++i) {
            pre += s[i];
        }
        pre = sub(pre, one);
        for (int i = halflen - 1; i >= 0; --i) {
            suf += pre[i];
        }
        string nw = pre + suf;
        v.push_back(nw);
        solve(sub(s, nw), lev - 1);
    } else {
        string pre, suf;
        for (int i = 0; i < halflen; ++i) {
            pre += s[i];
        }
        pre = sub(pre, one);
        if (zero(pre) || pre.length() < halflen) {
            for (int i = 0; i < halflen; ++i) {
                suf += '9';
            }
        } else {
            for (int i = halflen - 1; i >= 0; --i) {
                suf += pre[i];
            }
        }
        string nw = pre + suf;
        v.push_back(nw);
        solve(sub(s, nw), lev - 1);
    }
}
int main()
{
    one += '1';
    cin.tie(0)->sync_with_stdio(0);
    int z;
    cin >> z;
    while (z--) {
        string s;
        cin >> s;
        v.clear();
        solve(s, 25);
        int siz = sz(v);
        cout << siz << '\n';
        for (int i = 0; i < siz; ++i) {
            cout << v[i] << '\n';
        }
    }
    return 0;
}