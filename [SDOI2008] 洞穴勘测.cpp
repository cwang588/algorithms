#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
struct Node{
    int ch[2], fa, val, xsum;
    bool rev;
} tr[MAXN];
inline bool isleft(int p){
    return tr[tr[p].fa].ch[0] == p;
}
inline bool isroot(int p){
    return tr[tr[p].fa].ch[0] != p && tr[tr[p].fa].ch[1] != p;
}
inline void update(int p){
    tr[p].xsum = tr[p].val ^ tr[tr[p].ch[0]].xsum ^ tr[tr[p].ch[1]].xsum;
}
inline void reverse(int p){
    swap(tr[p].ch[0], tr[p].ch[1]);
    tr[p].rev ^= 1;
}
inline void pushdown(int p){
    if(tr[p].rev){
        if(tr[p].ch[0]) reverse(tr[p].ch[0]);
        if(tr[p].ch[1]) reverse(tr[p].ch[1]);
        tr[p].rev ^= 1;
    }
}
int sta[MAXN],stop;
inline void pushto(int p){
    stop = 0;
    while(!isroot(p)) {
        sta[stop++] = p;
        p = tr[p].fa;
    }
    sta[stop++] = p;
    while(stop) {
        pushdown(sta[--stop]);
    }
}
inline void rotate(int p) {
    bool t = !isleft(p); int fa = tr[p].fa, ffa = tr[fa].fa;
    tr[p].fa = ffa; if(!isroot(fa)) tr[ffa].ch[!isleft(fa)] = p;
    tr[fa].ch[t] = tr[p].ch[!t]; tr[tr[fa].ch[t]].fa = fa;
    tr[p].ch[!t] = fa; tr[fa].fa = p;
    update(fa);
}
inline void splay(int p) {
    pushto(p);
    for(int fa = tr[p].fa; !isroot(p); rotate(p), fa = tr[p].fa) {
        if(!isroot(fa)) rotate(isleft(fa) == isleft(p) ? fa : p);
    }
    update(p);
}
inline void access(int p) {
    for(int q = 0; p; q = p, p = tr[p].fa) {
        splay(p);
        tr[p].ch[1] = q;
        update(p);
    }
}
inline void makert(int p) {
    access(p);
    splay(p);
    reverse(p);
}
inline int findrt(int p) {
    access(p);
    splay(p);
    while(tr[p].ch[0]) p = tr[p].ch[0];
    return p;
}
inline void split(int u, int v) {
    makert(u);
    access(v);
    splay(v);
}
inline void link(int u, int v) {
    split(u, v);
    tr[u].fa = v;
}
inline void cut(int u, int v) {
    split(u, v);
    if(tr[v].ch[0] != u || tr[u].ch[1]) return;
    tr[u].fa = tr[v].ch[0] = 0;
}
inline void modify(int u, int w) {
    access(u);
    splay(u);
    tr[u].val = w;
    update(u);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		string t;
		int x,y;
		cin>>t>>x>>y;
		if(t=="Connect")link(x,y);
		else if(t=="Destroy")cut(x,y);
		else{
			makert(x);
			if(findrt(y)==x)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
