#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
int n,k,v[100005],depth[100005],sz[100005],son[100005];
long long ans;
bool usd[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs1(int now,int pre)
{
	depth[now]=depth[pre]+1;
	sz[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		sz[now]+=sz[to];
		if(sz[to]>sz[son[now]])son[now]=to;
	}
}
struct node
{
	int val,son[2],sz,cnt,rank;
}T[5000005];
int tot;
int sz[maxn], v[maxn], num[maxn], rd[maxn], son[maxn][2];
// 用于重新统计以p为根节点的子树中元素个数
struct treap
{
	int R;
	void pushup(int p) {
	    sz[p] = sz[ son[p][0] ] + sz[ son[p][1] ] + num[p];
	}
	// 左旋（d==0时），右旋（d==1时）
	void rot(int &p, int d) {
	    int k = son[p][d^1];
	    son[p][d^1] = son[k][d];
	    son[k][d] = p;
	    pushup(p);
	    pushup(k);
	    p = k;
	}
	// 插入一个数x
	void ins(int &p, int x) {
	    if (!p) {
	        p = ++sum;
	        sz[p] = num[p] = 1;
	        v[p] = x;
	        rd[p] = rand();
	        return;
	    }
	    if (v[p] == x) {
	        num[p] ++;
	        sz[p] ++;
	        return;
	    }
	    int d = (x > v[p]);
	    ins(son[p][d], x);
	    if (rd[p] < rd[ son[p][d] ]) rot(p, d^1);
	    pushup(p);
	}
	// 删除一个数x
	void del(int &p, int x) {
	    if (!p) return;
	    if (x < v[p]) del(son[p][0], x);
	    else if (x > v[p]) del(son[p][1], x);
	    else {
	        if (!son[p][0] && !son[p][1]) {
	            num[p] --; sz[p] --;
	            if (!num[p]) p = 0;
	        }
	        else if (!son[p][1]) {
	            rot(p, 1);
	            del(son[p][1], x);
	        }
	        else if (!son[p][0]) {
	            rot(p, 0);
	            del(son[p][0], x);
	        }
	        else {
	            int d = (rd[ son[p][0] > rd[ son[p][1] ] ]);
	            rot(p, d);
	            del(son[p][d], x);
	        }
	    }
	    pushup(p);
	}
	// 查询x数的排名
	int get_rank(int p, int x) {
	    if (!p) return 0;
	    if (v[p] == x) return sz[ son[p][0] ] + 1;
	    if (v[p] < x) return sz[ son[p][0] ] + num[p] + get_rank(son[p][1], x);
	    if (v[p] > x) return get_rank(son[p][0], x);
	}
	// 查询排名为x的数
	int func_find(int p, int x) {
	    if (!p) return 0;
	    if (sz[ son[p][0] ] >= x) return func_find(son[p][0], x);
	    else if (sz[ son[p][0] ] + num[p] < x)
	        return func_find(son[p][1], x-num[p]-sz[ son[p][0] ]);
	    else return v[p];
	}
	// 求x的前驱
	int pre(int p, int x) {
	    if (!p) return -INF;
	    if (v[p] >= x) return pre(son[p][0], x);
	    else return max(v[p], pre(son[p][1], x));
	}
	// 求x的后缀
	int suc(int p, int x) {
	    if (!p) return INF;
	    if (v[p] <= x) return suc(son[p][1], x);
	    else return min(v[p], suc(son[p][0], x));
	}
}
void query(int now,int pre,int lca)
{
	int d=k+depth[lca]*2-depth[now];
	if(d>depth[lca])
	{
		int tmp=v[lca]*2-v[now];
		if(tmp>=0)
		{
			//tr[tmp].insert(tr[tmp].root,d);
			ans+=tr[tmp].find(d)-1;
			//tr[tmp].del(tr[tmp].root,d);
		}
	}
	else return;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		query(to,now,lca);
	}
}
void update(int now,int pre,int type)
{
	tr[v[now]].insert(tr[v[now]].root,depth[now]);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		update(to,now,type);
	}
}
void dfs2(int now,int pre,bool keep)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||to==son[now])continue;
		dfs2(to,now,false);
	}
	if(son[now])dfs2(son[now],now,true),usd[son[now]]=true;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||to==son[now])continue;
		query(to,now,now);
		update(to,now,1);
	}
	tr[v[now]].insert(tr[v[now]].root,depth[now]);
	usd[son[now]]=false;
	if(!keep)
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre||usd[to])continue;
			update(to,now,-1);
		}
		tr[v[now]].del(tr[v[now]].root,depth[now]);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	for(int i=2;i<=n;++i)
	{
		int fa;
		scanf("%d",&fa);
		add(i,fa);
		add(fa,i);
	}
	dfs1(1,0);
	dfs2(1,0,true);
	printf("%lld\n",ans*2);	
	return 0;
} 
