#include<bits/stdc++.h>
using namespace std;
const int N=50005;
const int INF=2147483647;
struct node
{
	int val,son[2],sz,cnt,rank;
}T[N*40];
struct Node
{
	int l,r,rt;
}seg[N*4];
int a[N],n,tot;
struct treap
{
	inline int Rand()
	{	
		static long long  r=2333;
		return (r*=233333LL)%=2147483647;
	}
	int root;
	treap()
	{
		root=build(-INF);
		T[root].son[1]=build(INF);
		push_up(root);
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
			if(T[now].val==x)return ans+T[T[now].son[0]].sz+1;
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
	inline int pre(int val)
	{
		int now=root,pre=0;
		while(now)
		{
			if(T[now].val<val)
			{
				pre=T[now].val;
				now=T[now].son[1];
			}
			else now=T[now].son[0];
		}
		return pre;
	}
	inline int nxt(int val)
	{
		int now=root,nxt=0;
		while(now)
		{
			if(T[now].val>val)
			{
				nxt=T[now].val;
				now=T[now].son[0];
			}
			else now=T[now].son[1];
		}
		return nxt;
	}
}tr[N*4];
void build(int l,int r,int rt)
{
	for(int i=l;i<=r;++i)tr[rt].insert(tr[rt].root,a[i]);
	if(l==r)return;
	int m=(l+r)>>1;
	build(l,m,rt<<1);	
	build(m+1,r,rt<<1|1);	
}
void modify(int l,int r,int rt,int pos,int k)
{
	tr[rt].del(tr[rt].root,a[pos]);
	tr[rt].insert(tr[rt].root,k);
	if(l==r)return;
	int m=(l+r)>>1;
	if(m>=pos)modify(l,m,rt<<1,pos,k);
	else modify(m+1,r,rt<<1|1,pos,k);
}
int queryrank(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		tr[rt].insert(tr[rt].root,k);
		int ans=tr[rt].find(k)-2;
		tr[rt].del(tr[rt].root,k);
		return ans;
	}
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re+=queryrank(l,m,rt<<1,nowl,nowr,k);
	if(m<nowr)re+=queryrank(m+1,r,rt<<1|1,nowl,nowr,k);
	return re;
}
int queryx(int nowl,int nowr,int k)
{
	int l=0,r=100000000;
	while(l<r-1)
	{
		int m=(l+r)>>1;
		if(queryrank(1,n,1,nowl,nowr,m)>k-1)r=m;
		else l=m;
	}
	if(queryrank(1,n,1,nowl,nowr,r)==k-1)return r;
	return l;
}
int querypre(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		tr[rt].insert(tr[rt].root,k);
		int ans=tr[rt].pre(k);
		tr[rt].del(tr[rt].root,k);
		return ans;
	}
	int re=-INF;
	int m=(l+r)>>1;
	if(m>=nowl)re=max(re,querypre(l,m,rt<<1,nowl,nowr,k));
	if(m<nowr)re=max(re,querypre(m+1,r,rt<<1,nowl,nowr,k));
	return re;
}
int querynxt(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		tr[rt].insert(tr[rt].root,k);
		int ans=tr[rt].nxt(k);
		tr[rt].del(tr[rt].root,k);
		return ans;
	}
	int re=INF;
	int m=(l+r)>>1;
	if(m>=nowl)re=min(re,querynxt(l,m,rt<<1,nowl,nowr,k));
	if(m<nowr)re=min(re,querynxt(m+1,r,rt<<1,nowl,nowr,k));
	return re;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",queryrank(1,n,1,l,r,x));
		}
		else if(t==2)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",queryx(l,r,x));
		}
		else if(t==3)
		{
			int pos,x;
			scanf("%d%d",&pos,&x);
			modify(1,n,1,pos,x);
		}
		else if(t==4)
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
