#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val,fa,son[2],sz,tot,cnt,num;
	void init(int x)
	{
		fa=son[0]=son[1]=0;
		tot=val=x;
		sz=cnt=num=1;
	}
}T[500005];
int szz;
struct Splay_tree
{
	int root;
	inline void clear(int x)
	{
		T[x].fa=T[x].son[0]=T[x].cnt=T[x].tot=T[x].sz=T[x].son[1]=T[x].val=0;
	}
	inline int get(int x)
	{
		return T[T[x].fa].son[1]==x;
	}
	inline void update(int x)
	{
		if(x)
		{
			T[x].sz=T[x].cnt;
			if(T[x].son[0])T[x].sz+=T[T[x].son[0]].sz;
			if(T[x].son[1])T[x].sz+=T[T[x].son[1]].sz;
			T[x].tot=T[x].cnt*T[x].val;
			if(T[x].son[0])T[x].tot+=T[T[x].son[0]].tot;
			if(T[x].son[1])T[x].tot+=T[T[x].son[1]].tot;
			T[x].num=1;
			if(T[x].son[0])T[x].num+=T[T[x].son[0]].num;
			if(T[x].son[1])T[x].num+=T[T[x].son[1]].num;
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
	inline void insert(int v)
	{
		if(!root)
		{
			++szz;
			T[szz].init(v);
			root=szz;
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
				++szz;
				T[szz].init(v);
				T[szz].fa=fa;
				if(T[fa].val<v)T[fa].son[1]=szz;
				else T[fa].son[0]=szz;
				update(fa);
				splay(szz,0);
				break;
			}
		}
	}
	inline int find(int x)
	{
		int ans=0,now=root;
		while(1)
		{
			if(!now)return ans;
			if(T[now].val>x)now=T[now].son[0];
			else 
			{
				ans+=(T[now].son[0]?T[T[now].son[0]].sz:0);
				if(T[now].val==x)
				{
					splay(now,0);
					return ans+T[now].cnt;
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
}s;
int a[500005];
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
int main()
{
	long long ans=0;
	int n;
	io>>n;
	for(int i=1;i<=n;++i)io>>a[i];//scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		ans+=i-1-s.find(a[i]);
		s.insert(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 
