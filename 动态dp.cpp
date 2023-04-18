#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int INF=192608177;
struct edge{
	int from,to,nxt;
}e[N<<1];
int Head[N],cnt,sz[N],son[N];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int value[N],f[N][2],g[N][2];
void dfs(int now,int pre){
	sz[now]=1;
	g[now][1]=value[now];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
		if(sz[to]>sz[son[now]])son[now]=to;
		g[now][0]+=max(g[to][0],g[to][1]);
		g[now][1]+=g[to][0];
	}
}
void dfss(int now,int pre){
	if(!son[now])return;
	g[now][0]-=max(g[son[now]][0],g[son[now]][1]);
	g[now][1]-=g[son[now]][0];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now);
	}
}
struct matrix{
	int s[2][2];
	matrix(){
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j)s[i][j]=-INF;
		}
	}
	matrix(int x){
		s[0][0]=s[1][1]=0;
		s[0][1]=s[1][0]=-INF;
	}
	friend matrix operator*(matrix a,matrix b){
		matrix c;
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j){
				for(int k=0;k<=1;++k)c.s[i][j]=max(c.s[i][j],b.s[i][k]+a.s[k][j]);
			}
		}
		return c;
	}
	int getmx(){
		return max(max(s[0][0],s[0][1]),max(s[1][0],s[1][1]));
	}
};
namespace bst{
	bool isroot[N];
	matrix W[N],S[N];
	int so[N][2],fa[N],sta[N],tp,ssz[N],rt;
	void update(int now){
		S[now]=S[so[now][0]]*W[now]*S[so[now][1]];
	}
	void getpoi(int now){
		W[now].s[0][0]=W[now].s[0][1]=g[now][0];
		W[now].s[1][0]=g[now][1];
	}
	int build_tree(int l,int r){
		if(l>r)return 0;
		int tot=0,cnt=0;
		for(int i=l;i<=r;++i)tot+=ssz[sta[i]];
		for(int i=l;i<=r;++i){
			cnt+=ssz[sta[i]];
			if(cnt*2>=tot){
				int rs=build_tree(l,i-1),ls=build_tree(i+1,r);
				so[sta[i]][0]=ls,so[sta[i]][1]=rs;
				fa[ls]=fa[rs]=sta[i];
				update(sta[i]);
				return sta[i];
			}
		}
	}
	int build(int top,int fr){
		for(int i=top;i;fr=i,i=son[i]){
			for(int j=Head[i];j;j=e[j].nxt){
				if(e[j].to==fr||e[j].to==son[i])continue;
				fa[build(e[j].to,i)]=i;
			}
			getpoi(i);
		}
		tp=0;
		for(int i=top;i;i=son[i]){
			sta[++tp]=i;
			ssz[i]=sz[i]-sz[son[i]];
		}
		return build_tree(1,tp);
	}
	void modify(int pos,int val){
		g[pos][1]+=val-value[pos];
		value[pos]=val;
		int dp[2][2];
		for(int now=pos;now;now=fa[now]){
			dp[0][0]=max(S[now].s[0][0],S[now].s[0][1]);
			dp[0][1]=max(S[now].s[1][0],S[now].s[1][1]);
			getpoi(now),update(now);
			dp[1][0]=max(S[now].s[0][0],S[now].s[0][1]);
			dp[1][1]=max(S[now].s[1][0],S[now].s[1][1]);
			if(isroot[now]){
				g[fa[now]][0]+=max(dp[1][0],dp[1][1])-max(dp[0][0],dp[0][1]);
				g[fa[now]][1]+=dp[1][0]-dp[0][0];
			}
		}
	}
}
using namespace bst;
int main(){
	ios::sync_with_stdio(false);
	int n,m;	
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>value[i];
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	dfss(1,0);
	W[0]=S[0]=matrix(0);
	int rt=build(1,0);
	for(int i=1;i<=n;++i)if(so[fa[i]][0]!=i&&so[fa[i]][1]!=i)isroot[i]=true;
	int lastans=0;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		x^=lastans;
		modify(x,y);
		lastans=S[rt].getmx();
		printf("%d\n",lastans);
	}
	return 0;
}