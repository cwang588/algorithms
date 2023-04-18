#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
vector<int>v[100005];
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
int Splay_sz;
struct Splay_tree
{
	int root;
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
	void splay(int x,int goal)
	{
		if(x==goal)return;
		while(T[x].fa!=goal)
		{
			int y=T[x].fa,z=T[y].fa;
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
			++Splay_sz;
			T[Splay_sz].init(v);
			root=Splay_sz;
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
				++Splay_sz;
				T[Splay_sz].init(v);
				T[Splay_sz].fa=fa;
				if(T[fa].val<v)T[fa].son[1]=Splay_sz;
				else T[fa].son[0]=Splay_sz;
				update(fa);
				splay(Splay_sz,0);
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
		int now=find(x);//不能删！要不然转不上去了！ 
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
Splay_tree s[100005];
int fa[100005],value[100005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	int r1=getfa(x),r2=getfa(y);
	if(r1==r2)return;
	if(T[s[r1].root].sz>T[s[r2].root].sz)swap(r1,r2);
	fa[r1]=r2;
	int len=v[r1].size();
	for(int i=0;i<len;++i)s[r2].insert(v[r1][i]),v[r2].push_back(v[r1][i]);
}
int pos[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,scanf("%d",&value[i]),s[i].insert(value[i]),v[i].push_back(value[i]),pos[value[i]]=i;
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		Merge(x,y);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char t;
		int x,y;
		cin>>t>>x>>y;
		if(t=='Q'){
			x=getfa(x);
			int now=T[s[x].root].sz;
			if(now>=y)printf("%d\n",pos[s[x].findx(y)]);
			else printf("-1\n");
		}
		else Merge(x,y);
	}
	return 0;
}
