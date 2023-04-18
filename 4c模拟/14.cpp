#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
int n;
vector<int> p;
pa u[10000],d[10000];
int uc,dc;
map<int,int> vis,up,down;
int lx,ly,rx,ry;
inline bool pupl(const pa &p1,const pa &p2,const pa &p3) {
    return (ll)(p3.first - p2.first) * (p2.second - p1.second) > (ll)(p2.first - p1.first) * (p3.second - p2.second);
}
inline bool pdownl(const pa &p1,const pa &p2,const pa &p3) {
    return (ll)(p3.first - p2.first) * (p2.second - p1.second) < (ll)(p2.first - p1.first) * (p3.second - p2.second);
}
int main() {
    int x,y1,y2;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++) {
        scanf("%d%d%d",&x,&y1,&y2);
        if(vis[x] == 0) {
            p.push_back(x);
            vis[x] = 1;
            up[x] = y1;
            down[x] = y2;
        }
        else {
            up[x] = min(up[x],y1);
            down[x] = min(down[x],y2);
        }
    }
    if(p.size() == 1) {
        lx = p[0];
        ly = up[p[0]];
        rx = p[0];
        ry = down[p[0]];
    }
    else {
        sort(p.begin(),p.end());
        for(int i = 0;i < p.size();i ++) {
            while(uc >= 2 && pupl(u[uc - 2],u[uc - 1],pa(p[i],up[p[i]]))) uc --;
            u[uc ++] = pa(p[i],up[p[i]]);
            while(dc >= 2 && pdownl(d[dc - 2],d[dc - 1],pa(p[i],down[p[i]]))) dc --;
            d[dc ++] = pa(p[i],down[p[i]]);
        }
        int i,j;
        for(i = 0;i < uc - 1;i ++) {
            for(j = 0;j < dc;j ++) {
                if(pupl(u[i],d[j],u[i + 1])) break;
            }
            if(j == dc) break;
        }
        if(i == uc - 1) {
            for(i = 0;i < dc - 1;i ++) {
                for(j = 0;j < uc;j ++) {
                    if(pdownl(d[i],u[j],d[i + 1])) break;
                }
                if(j == uc) break;
            }
            lx = d[i].first;
            ly = d[i].second;
            rx = d[i + 1].first;
            ry = d[i + 1].second;
        }
        else {
            lx = u[i].first;
            ly = u[i].second;
            rx = u[i + 1].first;
            ry = u[i + 1].second;
        }
    }
    printf("%d %d %d %d",lx,ly,rx,ry);
}
