#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << "? 1 1" << endl;
        int dis;
        cin >> dis;
        if (dis < n && dis < m) {
            cout << "? " << dis + 1<< " " << dis + 1<< endl;
            int tmp;
            cin >> tmp;
            cout << "? " << dis + 1 << " " << dis + 1 - tmp << endl;
            int now;
            cin >> now;
            if (now)cout << "! " << dis + 1 - tmp << " " << dis + 1 << endl;
            else cout << "! " << dis + 1 << " " << dis + 1 - tmp << endl;
        } else if (dis >= n) {
            cout << "? 1 " << dis + 1 << endl;
            int tmp;
            cin >> tmp;
            cout << "! " << tmp + 1 << " " << dis + 1 << endl;
        } else {
            cout << "? " << dis + 1 << " 1" << endl;
            int tmp;
            cin >> tmp;
            cout << "! " << dis + 1 << " " << tmp + 1 << endl;
        }
    }
    return 0;
}
