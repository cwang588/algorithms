#include <bits/stdc++.h>

using namespace std;
int n,m;
int getValue(int x,int y){
    int re=4;
    if(x==1||x==n)--re;
    if(y==1||y==m)--re;
    return re;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 2147483647;
        if (abs(x1 - x2) > 1)ans = min(ans, m);
        if (abs(y1 - y2) > 1)ans = min(ans, n);
        ans=min(ans,getValue(x1,y1)),ans=min(ans,getValue(x2,y2));
        cout<<ans<<"\n";
    }
    return 0;
}
