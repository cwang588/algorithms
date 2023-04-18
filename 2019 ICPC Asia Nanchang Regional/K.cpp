#include<bits/stdc++.h>
#define int long long
using namespace std;
unordered_map<long long,long long>m;
struct ios {
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }

    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char ch,sgn; ch = gc(), sgn = 0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc())x=x*10+(ch^'0');
        sgn&&(x=-x); return *this;
    }
} io;
const long long p1=19260817;
const unsigned long long p2=998244353;
int n,k,v[100005],depth[100005],sz[100005],son[100005];
long long ans;
int usd[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
inline void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
inline long long Hash(int x,int y)
{
	long long xx=x,yy=y;
	return xx*p1+yy;
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
//inline long long calc(int num,int x)
//{
//	if(x<=0)return 0;
//	long long re=0;
//	while(x)
//	{
//		re+=m[Hash(num,x)];
//		x-=lowbit(x);
//	}
//	return re;
//}
//inline void Add(int num,int x,long long k)
//{
//	while(x<=n)
//	{
//		m[Hash(num,x)]+=k;
//		x+=lowbit(x);
//	}
//}

typedef long long LL;

const int maxm = 2e6+26;

const int maxn = 1e5+15;

struct data{int l,r,v,size,fix,w;}tr[maxm];

int len,root[maxn];

void update(int k){tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;}

void rturn(int &k){int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;tr[t].size=tr[k].size;update(k);k=t;}

void lturn(int &k){int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;tr[t].size=tr[k].size;update(k);k=t;}

void Insert(int &k,int x)                        //插入数x

{

    if(k==0){len++;k=len;tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].fix=rand();return;}

    tr[k].size++;

    if(tr[k].v==x)tr[k].w++;

    else if(x>tr[k].v){Insert(tr[k].r,x);if(tr[tr[k].r].fix<tr[k].fix)lturn(k);}

    else {Insert(tr[k].l,x);if(tr[tr[k].l].fix<tr[k].fix)rturn(k);} 

} 

void Delete(int &k,int x)                        //删除数x

{

    if(k==0) return; 

    if(tr[k].v==x)

    {

        if(tr[k].w>1){tr[k].w--;tr[k].size--;return;}

        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;

        else if(tr[tr[k].l].fix<tr[tr[k].r].fix) rturn(k),Delete(k,x);

        else lturn(k),Delete(k,x);

    }

    else if(x>tr[k].v) tr[k].size--,Delete(tr[k].r,x);

    else tr[k].size--,Delete(tr[k].l,x);

}

/*

    查找x的排名

    返回 <= x 的数量,等于x的数有多个,只算一个

*/

int Findrank(int k,int x)                    

{

    if(k==0) return 0;

    if(tr[k].v==x) return tr[tr[k].l].size+tr[k].w;

    else if(x>tr[k].v) return tr[tr[k].l].size+tr[k].w+Findrank(tr[k].r,x);

    else return Findrank(tr[k].l,x);

}

int Findkth(int k,int x)                        //查找排名为x的数

{

    if(k==0) return 0;

    if(x<=tr[tr[k].l].size) return Findkth(tr[k].l,x);

    else if(x>tr[tr[k].l].size+tr[k].w) return Findkth(tr[k].r,x-tr[tr[k].l].size-tr[k].w);

    else return tr[k].v;

}
void query(int now,int pre,int lca)
{
	int d=k+depth[lca]*2-depth[now];
	if(d>depth[lca])
	{
		int tmp=2*v[lca]-v[now];
		if(tmp>=0&&tmp<=n)
			ans+=Findrank(root[tmp],d);
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
	if(type==1)Insert(root[v[now]],depth[now]);
	else Delete(root[v[now]],depth[now]);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		update(to,now,type);
	}
}
void dfs2(int now,int pre,int keep)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||to==son[now])continue;
		dfs2(to,now,0);
	}
	if(son[now])dfs2(son[now],now,1),usd[son[now]]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to]||to==pre)continue;
		query(to,now,now);
		update(to,now,1);
	}
	Insert(root[v[now]],depth[now]);
	usd[son[now]]=0;
	if(!keep)
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(usd[to]||to==pre)continue;
			update(to,now,-1);
		}
		Delete(root[v[now]],depth[now]);
	}
}
signed main()
{
	io>>n>>k;
//	scanf("%d%d",&n,&k);
	for(register int i=1;i<=n;++i)//scanf("%d",&v[i]);
	io>>v[i];
	for(register int i=2;i<=n;++i)
	{
		int fa;
		io>>fa;
//		scanf("%d",&fa);
		add(i,fa);
		add(fa,i);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	printf("%lld\n",ans*2);	
	return 0;
} 
