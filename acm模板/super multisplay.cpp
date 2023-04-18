#include<bits/stdc++.h>
using namespace std;
const int N=1000005,INF=2147483647;
struct Node
{
	int val,Max,add,sz,son[2];
	bool rev;
	void init(int _val)
	{
		val=Max=_val,sz=1;
		add=rev=son[0]=son[1]=0;
	}
}T[N];
int fa[N],root[N];
void push_up(int x)
{
	T[x].Max=T[x].val,T[x].sz=1;
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
void Rorate(int x,int kind)//0×óÐý1ÓÒÐý 
{
	int y=fa[x],z=fa[y];
	T[y].son[!kind]=T[x].son[kind],fa[T[x].son[kind]]=y;
	T[x].son[kind]=y,fa[y]=x;
	T[z].son[T[z].son[1]==y]=x,fa[x]=z;
	push_up(y);
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
void Splay(int x,int goal)
{
	if(x==goal)return;
	while(fa[x]!=goal)
	{
		int y=fa[x],z=fa[y];
		push_down(z);
		push_down(y);
		push_down(x);
		int rx=T[y].son[0]==x,ry=T[z].son[0]==y;
		if(goal==z)Rorate(x,rx);
		else
		{
			if(rx==ry)Rorate(y,ry);
			else Rorate(x,rx);
			Rorate(x,ry);
		}
	}
	push_up(x);
	if(!goal)root=x;
}
int select(int pos)
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
void update(int l,int r,int val)
{
	int u=select(l-1),v=select(r+1);
	Splay(u,0);
	Splay(v,u);
	T[T[v].son[0]].add+=val;
	T[T[v].son[0]].Max+=val;
	T[T[v].son[0]].val+=val;
}
void reverse(int l,int r)
{
	int u=select(l-1),v=select(r+1);
	Splay(u,0);
	Splay(v,u);
	T[T[v].son[0]].rev^=1;
}
int query(int l,int r)
{
	int u=select(l-1),v=select(r+1);
	Splay(u,0);
	Splay(v,u);
	return T[T[v].son[0]].Max;
}
int build(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return r;
	int m=(l+r)>>1,sl,sr;
	T[m].son[0]=sl=build(l,m-1);
	T[m].son[1]=sr=build(m+1,r);
	fa[sl]=fa[sr]=m;
	push_up(m);
	return m;
}
void init(int n)
{
	T[0].init(-INF),T[1].init(-INF),T[n+2].init(-INF);
	for(int i=2;i<=n+1;++i)T[i].init(0);
	root=build(1,n+2);
	fa[root]=0;
	fa[0]=0;
	T[0].son[1]=root;
	T[0].sz=0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	hehe.init(n);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			hehe.update(a,b,c);
		}
		else if(t==2)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			hehe.reverse(a,b);	
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",hehe.query(a,b));
		}
	}
	return 0;
}
