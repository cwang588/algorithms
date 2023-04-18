//×îÇ¿°æ±¾ 
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct Splay_tree
{
	struct node
	{
		int val,fa,son[2],sz,cnt,add,Max;
		bool rev;
		void init(int x)
		{
			fa=son[0]=son[1]=rev=add=0;
			Max=val=x;
			sz=cnt=1;
		}
	}T[N];
	int root,sz;
	inline void clear(int x)
	{
		T[x].fa=T[x].son[0]=T[x].cnt=T[x].sz=T[x].son[1]=T[x].val=0;
	}
	inline int get(int x)
	{
		return T[T[x].fa].son[1]==x;
	}
	inline void update(int x)
	{
		if(x)
		{
			T[x].Max=T[x].val;
			T[x].sz=T[x].cnt;
			if(T[x].son[0])
			{
				T[x].Max=max(T[x].Max,T[T[x].son[0]].Max);
				T[x].sz+=T[T[x].son[0]].sz;
			}
			if(T[x].son[1])
			{
				T[x].Max=max(T[x].Max,T[T[x].son[1]].Max);
				T[x].sz+=T[T[x].son[1]].sz;
			}
		}
	}
//	inline void splay(int x,int y)
//	{
//		if(x==y)return;
//		int f=T[x].fa;
//		while(f!=y)
//		{
//			rorate(x);
//			f=T[x].fa;
//			if(f!=y)
//			{
//				rorate(get(x)==get(T[x].fa)?T[x].fa:x);
//				rorate(x);
//			}
//			f=T[x].fa;
//		}
//		if(y==0)root=x;
//	}
	void splay(int x,int goal)
	{
		if(x==goal)return;
		while(T[x].fa!=goal)
		{
			int y=T[x].fa,z=T[y].fa;
		//	push_down(z);
		//	push_down(y);
		//	push_down(x);
			int rx=T[y].son[0]==x,ry=T[z].son[0]==y;
			if(goal==z)rorate(x);
			else
			{
				if(rx==ry)rorate(y);
				else rorate(x);
				rorate(x);
			}
		}
		update(x);
		if(!goal)root=x;
	}
	inline void rorate(int x)
	{
		int old=T[x].fa,oldf=T[old].fa,which=get(x);
		T[old].son[which]=T[x].son[which^1];
		T[T[old].son[which]].fa=old;
		T[old].fa=x;
		T[x].son[which^1]=old;
		T[x].fa=oldf;
		if(oldf)T[oldf].son[T[oldf].son[1]==old]=x;
		update(old);
		update(x);
	}
	void push_down(int x)
	{
		if(x==0)return;
		if(T[x].add)
		{
			if(T[x].son[0])
			{
				T[T[x].son[0]].Max+=T[x].add;
				T[T[x].son[0]].val+=T[x].add;
				T[T[x].son[0]].add+=T[x].add;
			}
			if(T[x].son[1])
			{
				T[T[x].son[1]].Max+=T[x].add;
				T[T[x].son[1]].val+=T[x].add;
				T[T[x].son[1]].add+=T[x].add;
			}
			T[x].add=0;
		}
		if(T[x].rev)
		{
			if(T[x].son[0])T[T[x].son[0]].rev^=1;
			if(T[x].son[1])T[T[x].son[1]].rev^=1;
			swap(T[x].son[0],T[x].son[1]);
			T[x].rev=0;
		} 
	}
	inline void insert(int v)
	{
		if(!root)
		{
			++sz;
			T[sz].init(v);
			root=sz;
			return;
		}
		int now=root,fa=0;
		while(1)
		{
			if(T[now].val==v)
			{
				++T[now].cnt;
				update(now);
				update(fa);
				splay(now,0);
				break;
			}
			fa=now;
			if(T[now].val<v)now=T[now].son[1];
			else now=T[now].son[0];
			if(!now)
			{
				++sz;
				T[sz].init(v);
				T[sz].fa=fa;
				if(T[fa].val<v)T[fa].son[1]=sz;
				else T[fa].son[0]=sz;
				update(fa);
				splay(sz,0);
				break;
			}
		}
	}
	inline int find(int x)
	{
		int ans=0,now=root;
		while(1)
		{
			if(T[now].val>x)now=T[now].son[0];
			else 
			{
				ans+=(T[now].son[0]?T[T[now].son[0]].sz:0);
				if(T[now].val==x)
				{
					splay(now,0);
					return ans+1;
				}
				ans+=T[now].cnt;
				now=T[now].son[1];
			}
		}
	}
	int findx(int x)
	{
		int tot=0,now=root;
		while(1)
		{
			if(T[now].son[0]&&T[T[now].son[0]].sz+tot>=x)now=T[now].son[0];
			else
			{
				tot+=(T[now].son[0]?T[T[now].son[0]].sz:0);
				if(tot+T[now].cnt>=x)return T[now].val;
				tot+=T[now].cnt;
				now=T[now].son[1];
			}
		}	
	}
	inline int pre()
	{
		int now=T[root].son[0];
		while(T[now].son[1])now=T[now].son[1];
		return now;
	}
	inline int nxt()
	{
		int now=T[root].son[1];
		while(T[now].son[0])now=T[now].son[0];
		return now;
	}
	inline void del(int x)
	{
		int now=find(x);
		if(T[root].cnt>1)
		{
			--T[root].cnt;
			update(root);
			return;
		}
		if(!T[root].son[0]&&!T[root].son[1])
		{
			clear(root);
			root=0;
			return;
		}
		if(!T[root].son[0])
		{
			int tmp=root;
			root=T[root].son[1];
			T[root].fa=0;
			clear(tmp);
			return;
		}		
		if(!T[root].son[1])
		{
			int tmp=root;
			root=T[root].son[0];
			T[root].fa=0;
			clear(tmp);
			return;
		}
		int lf=pre(),tmp=root;
		splay(lf,0);
		T[T[tmp].son[1]].fa=root;
		T[root].son[1]=T[tmp].son[1];
		clear(tmp);
		update(root);
	}
	inline int Pre(int x)
	{
		insert(x);
		int ans=pre();
		del(x);
		return T[ans].val;	
	}
	inline int Nxt(int x)
	{
		insert(x);
		int ans=nxt();
		del(x);
		return T[ans].val;		
	}
	inline int select(int pos)
	{
		int u=root;
		push_down(u);
		while(T[T[u].son[0]].sz!=pos)
		{
			if(pos<T[T[u].son[0]].sz)u=T[u].son[0];
			else 
			{
				pos-=T[T[u].son[0]].sz+1;
				u=T[u].son[1];
			}
			push_down(u);
		}
		return u;
	}
	inline void modify(int l,int r,int val)
	{
		int u=select(l-1);
		int v=select(r+1);
		splay(u,0);
		splay(v,u);
		T[T[v].son[0]].add+=val;
		T[T[v].son[0]].Max+=val;
		T[T[v].son[0]].val+=val;
	}
	inline int query(int l,int r)
	{
		int u=select(l-1),v=select(r+1);
		splay(u,0);
		splay(v,u);
		return T[T[v].son[0]].Max;
	}
	inline void reverse(int l,int r)
	{
		int u=select(l-1),v=select(r+1);
		splay(u,0);
		splay(v,u);
		T[T[v].son[0]].rev^=1;
	}
};
Splay_tree s;
int n;
//void sb(int now)
//{
//	s.push_down(now);
//	if(s.T[now].son[0])sb(s.T[now].son[0]);
//	if(s.T[now].son[1])sb(s.T[now].son[1]);	
//}
////void print(int now)
//{
//	if(s.T[now].son[0])print(s.T[now].son[0]);
//	if(s.T[now].val!=n+1&&s.T[now].val)printf("%d ",s.T[now].val);
//	if(s.T[now].son[1])print(s.T[now].son[1]);
//}
int build(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return l;
	int m=(l+r)>>1;
	s.T[m].son[0]=build(l,m-1);
	s.T[m].son[1]=build(m+1,r);
	s.T[s.T[m].son[0]].fa=s.T[s.T[m].son[1]].fa=m;
	s.update(m);
	return m;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	s.T[0].init(-2147483647);
	s.T[1].init(-2147483647);
//	for(int i=2;i<=n+1;++i)s.T[i].init(0);
//	s.T[n+2].init(-2147483647);
//	s.root=build(1,n+2);
//	s.T[s.root].fa=0;
//	s.T[0].fa=0;
//	s.T[0].son[1]=s.root;
//	s.T[0].sz=0;
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			s.modify(l,r,x);
		}
		else if(t==2)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			s.reverse(l,r);
		}
		else 
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",s.query(l,r));
		}
	}
//	sb(s.root);
//	print(s.root);
	return 0;
}
