#include<bits/stdc++.h>
using namespace std;
const int N=1000005,INF=214748647;
int ans[1000005];
struct treap
{
	inline int Rand()
	{	
		static long long  r=2333;
		return (r*=233333LL)%=2147483647;
	}
	struct node
	{
		int val,son[2],sz,cnt,rank;
	}T[N];
	int tot,root;
	treap()
	{
		tot=root=0;
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
}tr;
int main()
{
//	freopen("try1.out","w",stdout);
	srand((unsigned)time(NULL));
	int n;
	scanf("%d",&n);
	int ansnum=0;
	for(int i=1;i<=n;++i)
	{
		int t,k;
		scanf("%d%d",&t,&k);	
		if(t==1)tr.insert(tr.root,k);
		else if(t==2)tr.del(tr.root,k);
		else if(t==3)ans[++ansnum]=tr.find(k)-1;
		else if(t==4)ans[++ansnum]=tr.findx(k+1);
		else if(t==5)ans[++ansnum]=tr.pre(k);
		else ans[++ansnum]=tr.nxt(k);
	}
	for(int i=1;i<=ansnum;++i)printf("%d\n",ans[i]);	
	return 0;
}
