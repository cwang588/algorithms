#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const ll INF = 1e16+1;
int n,k;
ll a[35];
ll fac[63],num[63];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int cnt = 0;
        for(int i = 1;i <= n;++i){
            cin >> a[i];
        }
        fac[0] = 1;
        while(fac[cnt] < INF){
            fac[cnt+1] = fac[cnt] * k;
            cnt++;
        }
        for(int i = 0;i < cnt;++i){
            num[i] = 0;
        }
        bool flag = false;
        for(int i = 1;i <= n;++i){
            int now = cnt - 1;
            while(a[i] && now >= 0){
                if(a[i] >= fac[now])
                    a[i] -= fac[now],num[now]++;
                now--;
            }
            if(a[i] && now == -1)
                flag = true;
        }
        for(int i = 0;i < cnt;++i){
            if(num[i] >= 2)
                flag = true;
        }
        if(flag)
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
