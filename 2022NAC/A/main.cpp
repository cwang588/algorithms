#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> to[2005];
int last[2005];
bool dfs(int now,int day){
    if(day==0)return true;
    for(const auto &e:to[now]){
        if(e.second==day&&last[e.first]==day){
            if(dfs(e.first,day-1))return true;
        }
    }
    return false;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        to[x].emplace_back(y, z);
        to[y].emplace_back(x, z);
        last[x] = max(last[x], z);
        last[y] = max(last[y], z);
    }
    vector<int> ans;
    for(int i=1;i<=n;++i){
        if(last[i]==m){
            if(dfs(i,m))ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(const auto &x:ans)cout<<x<<"\n";
    return 0;
}
