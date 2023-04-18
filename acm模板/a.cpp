#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=50005;
const int INF=2147483647;
int m,n;
int a[50005];
struct Node
{
	int l,r;
}t[N*4];
struct node
{
	int val,son[2],sz,cnt,rank;
}T[N*40];
int tot;
struct treap
{
	inline int Rand()
	{	
		static long long  r=2333;
		return (r*=233333LL)%=2147483647;
	}
	int root,l,r;
	treap()
	{
	//	root=0;
	//	root=build(-INF);
	//	T[root].son[1]=build(INF);
	//	push_up(root);
	}
	inline void rorate(int &x,int k)
	{
		int now=T[x].son[k^1];
		T[x].son[k^1]=T[now].son[k];
		T[now].son[k]=x;
		x=now;
		push_up(T[x].son[k]);
		push_up(x);		
	}
	inline int build(int val)
	{
		T[++tot].val=val;
		T[tot].rank=Rand();
		T[tot].sz=T[tot].cnt=1;
		T[tot].son[0]=T[tot].son[1]=0;
		return tot;
	}
	inline void insert(int &x,int val)
	{
		if(!x)
		{
			x=build(val);
			return;
		}
		++T[x].sz;
		if(val==T[x].val)++T[x].cnt;
		else if(val<T[x].val)
		{
			insert(T[x].son[0],val);
			if(T[T[x].son[0]].rank>T[x].rank)rorate(x,1);
		}
		else
		{
			insert(T[x].son[1],val);
			if(T[T[x].son[1]].rank>T[x].rank)rorate(x,0);
		}
		push_up(x);
	}
	inline void push_up(int x)
	{
		T[x].sz=T[x].cnt;
		if(T[x].son[0])T[x].sz+=T[T[x].son[0]].sz;
		if(T[x].son[1])T[x].sz+=T[T[x].son[1]].sz;		
	}
	inline void del(int &x,int val)
	{
		if(!x)return;
		if(T[x].val==val)
		{
			if(T[x].cnt>1)
			{
				--T[x].cnt;
				push_up(x);
				return;
			}
			if(T[x].son[0]||T[x].son[1])
			{
				if(!T[x].son[1]||T[T[x].son[0]].rank>T[T[x].son[1]].rank)
				{
					rorate(x,1);
					del(T[x].son[1],val);
				}
				else
				{
					rorate(x,0);
					del(T[x].son[0],val);
				}
			}
			else x=0;
		}
		else if(T[x].val>val)del(T[x].son[0],val);
		else del(T[x].son[1],val);
		push_up(x);
	}
	inline int find(int x)
	{
		int now=root,ans=0;
		while(now)
		{
			if(T[now].val==x)return ans+T[T[now].son[0]].sz;
			else if(T[now].val>x)now=T[now].son[0];
			else
			{
				ans+=T[T[now].son[0]].sz+T[now].cnt;
				now=T[now].son[1];
			}
		}
		return ans;
	}
	inline int findx(int x)
	{
		int now=root;
		while(now)
		{
			if(T[T[now].son[0]].sz>=x)now=T[now].son[0];
			else
			{
				x-=T[T[now].son[0]].sz;
				if(T[now].cnt>=x)return T[now].val;
				else
				{
					x-=T[now].cnt;
					now=T[now].son[1];
				}
			}
		}
	}
	inline int pre(int now,int val)
	{
		if(!now)return -2147483647;
		if(T[now].val>=val)return pre(T[now].son[0],val);
		else return max(T[now].val,pre(T[now].son[1],val));
	}
	inline int nxt(int now,int val)
	{
		if(!now)return 2147483647;
		if(T[now].val<=val)return nxt(T[now].son[1],val);
		else return min(T[now].val,nxt(T[now].son[0],val));
	}
	bool exist(int now,int x)
	{
		if(T[now].val==x)return true;
		if(T[now].val>x)
		{
			if(!T[now].son[0])return false;
			return exist(T[now].son[0],x);
		}
		else
		{
			if(!T[now].son[1])return false;
			return exist(T[now].son[1],x);
		}
	}
}tr[N*4];
bool queryexist(int l,int r,int rt,int nowl,int nowr,int x)
{
	if(l>=nowl&&r<=nowr)return tr[rt].exist(tr[rt].root,x);
	int m=(l+r)>>1;
	bool re=false;
	if(m>=nowl)re|=queryexist(lson,nowl,nowr,x);
	if(m<nowr)re|=queryexist(rson,nowl,nowr,x);
	return re;
}
void build(int l,int r,int rt)
{
	for(int i=l;i<=r;++i)tr[rt].insert(tr[rt].root,a[i]);
	if(l==r)return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void modify(int l,int r,int rt,int pos,int k)
{
	tr[rt].del(tr[rt].root,a[pos]);
	tr[rt].insert(tr[rt].root,k);
	if(l==r)return;
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k);
	else modify(rson,pos,k);
}
int queryrank(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>nowr||r<nowl)return 0; 
	if(l>=nowl&&r<=nowr)return tr[rt].find(k);
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re+=queryrank(lson,nowl,nowr,k);
	if(m<nowr)re+=queryrank(rson,nowl,nowr,k);
	return re;
}
int querynum(int u,int v,int k)
{
	int l=0,r=100000000;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(queryrank(1,n,1,u,v,mid)<k)l=mid;
		else r=mid;
	}
	return l;
}
int querypre(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)return tr[rt].pre(tr[rt].root,k);
	int m=(l+r)>>1;
	int re=-2147483647;
	if(m>=nowl)re=max(re,querypre(lson,nowl,nowr,k));
	if(m<nowr)re=max(re,querypre(rson,nowl,nowr,k));
	return re;
}
int querynxt(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)return tr[rt].nxt(tr[rt].root,k);
	int m=(l+r)>>1;
	int re=2147483647;
	if(m>=nowl)re=min(re,querynxt(lson,nowl,nowr,k));
	if(m<nowr)re=min(re,querynxt(rson,nowl,nowr,k));
	return re;
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp==1)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",queryrank(1,n,1,l,r,k)+1);
		}
		else if(tmp==2)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querynum(l,r,k));
		}
		else if(tmp==3)
		{
			int pos,x;
			scanf("%d%d",&pos,&x);
			modify(1,n,1,pos,x);
		}
		else if(tmp==4)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querypre(1,n,1,l,r,k));
		}
		else 
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querynxt(1,n,1,l,r,k));
		}
	}
	return 0;
}
