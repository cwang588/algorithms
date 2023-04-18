#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>::iterator IT;
const int MAXQ = 1e6+7;
int dsu[MAXQ*2], query[MAXQ], type[MAXQ];
vector<int> vec;
int n, q;
inline int read()
{
    int w = 1, s = 0; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
    while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
    return w * s;
}
int getid(int x)
{
    IT iter = lower_bound(vec.begin(), vec.end(), x);
    if(*iter != x) return -1;
    return (iter - vec.begin());
}
int fnd(int x) { if(x == -1) return -1; return (dsu[x] == x) ? dsu[x] : dsu[x] = fnd(dsu[x]); }
void merge(int x, int y)
{
    if(vec[x] == n) { dsu[fnd(x)] = -1; return; }
    dsu[fnd(x)] = fnd(y);
}
int main()
{
    n = read(), q = read();
    for(int i = 1; i <= q; i++)
    {
        type[i] = read(), query[i] = read();
        if(type[i] == 1)
        {
            vec.push_back(query[i]);
            vec.push_back(query[i] + 1);
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int sz = vec.size();
    for(int i = 0; i < sz; i++) dsu[i] = i;
    for(int i = 1; i <= q; i++)
    {
        if(type[i] == 1)
        {
            ll idx = getid(query[i]), idy = idx + 1;
            merge(idx, idy);
        }else
        {
            ll idx = getid(query[i]);
            if(idx == -1) { printf("%d\n", query[i]); continue; }
            ll ans = fnd(idx);
            if(ans == -1) puts("-1");
            else printf("%d\n", vec[ans]);
        }
    }
//    system("pause");
}
