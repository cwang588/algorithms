#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long INF=1919810114514;
long long value[MAXN];
int fa[MAXN];
struct edge{
	int from,to,nxt;
}e[MAXN<<1];
int Head[MAXN],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct matrix{
	long long s[2][2];
	matrix(){
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j)s[i][j]=0;
		}
	}
	matrix operator*(const matrix &a)const{
		matrix b;
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j){
				for(int k=0;k<=1;++k){
					b.s[i][j]=max(b.s[i][j],s[i][k]+a.s[k][j]);
				}
			}
		}
		return b;
	}
}ret[MAXN],val[MAXN];
struct Node{
    int ch[2], fa;
}tr[MAXN];
inline bool isleft(int p){
    return tr[tr[p].fa].ch[0] == p;
}
inline bool isroot(int p){
    return tr[tr[p].fa].ch[0] != p && tr[tr[p].fa].ch[1] != p;
}
inline void update(int p){
    ret[p]=val[p];
    if(tr[p].ch[0])ret[p]=ret[tr[p].ch[0]]*ret[p];
    if(tr[p].ch[1])ret[p]=ret[p]*ret[tr[p].ch[1]];
}
int sta[MAXN],stop;
inline void rotate(int p) {
    bool t = !isleft(p); int fa = tr[p].fa, ffa = tr[fa].fa;
    tr[p].fa = ffa; if(!isroot(fa)) tr[ffa].ch[!isleft(fa)] = p;
    tr[fa].ch[t] = tr[p].ch[!t]; tr[tr[fa].ch[t]].fa = fa;
    tr[p].ch[!t] = fa; tr[fa].fa = p;
    update(fa);
}
inline void splay(int p) {
    for(int fa = tr[p].fa; !isroot(p); rotate(p), fa = tr[p].fa) {
        if(!isroot(fa)) rotate(isleft(fa) == isleft(p) ? fa : p);
    }
    update(p);
}
inline void access(int p) {
    for(int q = 0; p; q = p, p = tr[p].fa) {
        splay(p);
        val[p].s[0][0]+=max(ret[tr[p].ch[1]].s[0][0],ret[tr[p].ch[1]].s[1][0])-max(ret[q].s[0][0],ret[q].s[1][0]);
        val[p].s[1][0]+=ret[tr[p].ch[1]].s[0][0]-ret[q].s[0][0];
        val[p].s[0][1]=val[p].s[0][0];
        tr[p].ch[1] = q;
        update(p);
    }
}
inline void modify(int u, long long w) {
    access(u);
    splay(u);
    val[u].s[1][0]+=w-value[u];
    value[u]=w;
    update(u);
}
long long dp[MAXN][2];
void dfs(int now,int pre){
	dp[now][1]=value[now];
	fa[now]=pre;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		tr[to].fa=now;
		dp[now][0]+=max(dp[to][0],dp[to][1]);
		dp[now][1]+=dp[to][0];
	}
	val[now].s[0][0]=val[now].s[0][1]=dp[now][0];
	val[now].s[1][0]=dp[now][1];
	ret[now]=val[now];
	val[now].s[1][1]=-INF;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	string type;
	cin>>n>>m>>type;
	long long tot=0;
	for(int i=1;i<=n;++i)cin>>value[i],tot+=value[i];
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}	
	dfs(1,0);
	for(int i=1;i<=m;++i){
		int a,x,b,y;
		cin>>a>>x>>b>>y;
		if(!x&&!y&&(fa[a]==b||fa[b]==a)){
			cout<<"-1\n";
			continue;
		}
		if(x&&y){
			long long t1=value[a],t2=value[b];
			modify(a,-INF);
			modify(b,-INF);
			splay(1);
			long long ans;
			if(a!=1&&b!=1)ans=max(ret[1].s[0][0],ret[1].s[1][0]);
			else ans=ret[1].s[0][0];
			cout<<tot-ans<<"\n";
			modify(a,t1);
			modify(b,t2);
		}
		else if(x){
			long long t1=value[a],t2=value[b];
			modify(a,-INF);
			modify(b,INF);
			splay(1);
			long long ans;
			if(a!=1&&b!=1)ans=max(ret[1].s[0][0],ret[1].s[1][0]);
			else if(a==1)ans=ret[1].s[0][0];
			else ans=ret[1].s[1][0];
			ans-=INF-t2;
			cout<<tot-ans<<"\n";
			modify(a,t1);
			modify(b,t2);
		}
		else if(y){
			long long t1=value[a],t2=value[b];
			modify(a,INF);
			modify(b,-INF);
			splay(1);
			long long ans;
			if(a!=1&&b!=1)ans=max(ret[1].s[0][0],ret[1].s[1][0]);
			else if(b==1)ans=ret[1].s[0][0];
			else ans=ret[1].s[1][0];
			ans-=INF-t1;
			cout<<tot-ans<<"\n";
			modify(a,t1);
			modify(b,t2);
		}		
		else{
			long long t1=value[a],t2=value[b];
			modify(a,INF);
			modify(b,INF);
			splay(1);
			long long ans;
			if(a!=1&&b!=1)ans=max(ret[1].s[0][0],ret[1].s[1][0]);
			else ans=ret[1].s[1][0];
			ans-=INF*2-t1-t2;
			cout<<tot-ans<<"\n";
			modify(a,t1);
			modify(b,t2);
		}
	}
	return 0;
}