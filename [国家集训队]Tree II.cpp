#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const long long mod = 51061;
struct Node{
    int ch[2], fa;
    long long tot,val,col1,col2,sz;
    bool rev;
}tr[MAXN];
inline bool isleft(int p){
    return tr[tr[p].fa].ch[0] == p;
}
inline bool isroot(int p){
    return tr[tr[p].fa].ch[0] != p && tr[tr[p].fa].ch[1] != p;
}
inline void update(int p){
	tr[p].sz=1;tr[p].tot=tr[p].val;
	if(tr[p].ch[0]){
		tr[p].sz=(tr[p].sz+tr[tr[p].ch[0]].sz)%mod;
		tr[p].tot=(tr[p].tot+tr[tr[p].ch[0]].tot)%mod;
	}
	if(tr[p].ch[1]){
		tr[p].sz=(tr[p].sz+tr[tr[p].ch[1]].sz)%mod;
		tr[p].tot=(tr[p].tot+tr[tr[p].ch[1]].tot)%mod;
	}
}
inline void reverse(int p){
    swap(tr[p].ch[0], tr[p].ch[1]);
    tr[p].rev ^= 1;
}
inline void pushdown(int p){
    if(tr[p].col1||tr[p].col2!=1){
    	if(tr[p].ch[0]){
	    	tr[tr[p].ch[0]].val=(tr[tr[p].ch[0]].val*tr[p].col2+tr[p].col1)%mod;
	    	tr[tr[p].ch[0]].tot=(tr[tr[p].ch[0]].tot*tr[p].col2+tr[p].col1*tr[tr[p].ch[0]].sz)%mod;
	    	tr[tr[p].ch[0]].col2=(tr[tr[p].ch[0]].col2*tr[p].col2)%mod;
	    	tr[tr[p].ch[0]].col1=(tr[tr[p].ch[0]].col1*tr[p].col2+tr[p].col1)%mod;
	    }
	    if(tr[p].ch[1]){
	    	tr[tr[p].ch[1]].val=(tr[tr[p].ch[1]].val*tr[p].col2+tr[p].col1)%mod;
	    	tr[tr[p].ch[1]].tot=(tr[tr[p].ch[1]].tot*tr[p].col2+tr[p].col1*tr[tr[p].ch[1]].sz)%mod;
	    	tr[tr[p].ch[1]].col2=(tr[tr[p].ch[1]].col2*tr[p].col2)%mod;
	    	tr[tr[p].ch[1]].col1=(tr[tr[p].ch[1]].col1*tr[p].col2+tr[p].col1)%mod;	
	    }
		tr[p].col1=0;tr[p].col2=1;
	}
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
int main()
{
//	freopen("P1501_1.in","r",stdin);
//	freopen("tmp.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)tr[i].val=tr[i].tot=tr[i].sz=1;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		link(u,v);
	}
	for(int i=1;i<=m;++i){
		char tmp;
		cin>>tmp;
		if(tmp=='-'){
			int u1,v1,u2,v2;
			cin>>u1>>v1>>u2>>v2;
			cut(u1,v1);
			link(u2,v2);
		}
		else if(tmp=='+'){
			int u,v,val;
			cin>>u>>v>>val;
			split(u,v);
			tr[v].val=(tr[v].val+val)%mod;
			tr[v].tot=(tr[v].tot+val*tr[v].sz)%mod;
			tr[v].col1=(tr[v].col1+val)%mod;
		}
		else if(tmp=='*'){
			int u,v,val;
			cin>>u>>v>>val;
			split(u,v);
			tr[v].val=tr[v].val*val%mod;
			tr[v].tot=tr[v].tot*val%mod;
			tr[v].col1=tr[v].col1*val%mod;
			tr[v].col2=tr[v].col2*val%mod;
		}
		else{
			int u,v;
			cin>>u>>v;
			split(u,v);
			printf("%lld\n",tr[v].tot);
		}
	}
	return 0;
}
