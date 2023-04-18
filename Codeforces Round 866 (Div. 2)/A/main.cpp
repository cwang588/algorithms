#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if(s=="^"){
            cout<<"1\n";
            continue;
        }
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '_' && (i == 0 || s[i - 1] == '_'))++ans;
        }
        if (s[n - 1] == '_')++ans;
        cout << ans << "\n";
    }
    return 0;
}
