#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int num[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt,value[100005];
int ans[100005];
vector<int>v[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[100005];
int totnum;
int bh[100005];
//int lowbit(int x)
//{
//	return x&(-x);
//}
//int qq(int id,int x)
//{
//	if(!x)return 0;
//	int re=0;
//	while(x)
//	{
//		re+=sum[id][x];
//		x-=lowbit(x);
//	}
//	return re;
//}
//void add(int id,int x,int y)
//{
//	if(!x)
//	{
//		sum[id][0]+=y;
//		return;
//	}
//	while(x<=100000)
//	{
//		sum[id][x]+=y;
//		x+=lowbit(x);
//	}
//}
//int query(int id)
//{
//	if(!numm[id][0])return 0;
//	int l=0,r=100001;
//	while(l<r-1)
//	{
//		int m=(l+r)>>1;
//		int now=qq(id,m-1)+sum[id][0];
//		if(now==m)l=m;
//		else r=m;
//	}
//	return l;
//}
struct node
{
	int val,son[2],sz,cnt,rank;
	void clear()
	{
		val=son[0]=son[1]=sz=cnt=rank=0;
	}
}T[450005];
int tot;
struct treap
{
	int sum[100005],numm[100005];
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
	int query()
	{
		if(!sum[0])return 0;
		int ans=0,now=root,tmptot=0;
		while(now)
		{
			if(T[T[now].son[0]].sz+tmptot==T[now].val+1)tmptot+=T[T[now].son[0]].sz+1,ans=T[now].val,now=T[now].son[1];
			else now=T[now].son[0];
		}
		return ans+1;
	}
}tr[320];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=totnum=tot=0;
		memset(Head,0,sizeof(Head));
		memset(num,0,sizeof(num));
		memset(bh,0,sizeof(bh));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&value[i]);
		int base=sqrt(n);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			++num[x],++num[y];
		}
		for(int i=1;i<=n;++i)
			for(int j=Head[i];j;j=e[j].nxt)
			{
				int to=e[j].to;
				if(num[to]>base)v[i].push_back(to);
			}
		for(int i=1;i<=n;++i)
		{
			if(num[i]>=base)
			{
				bh[i]=++totnum;
				int tmpp=bh[i];
				for(int j=Head[i];j;j=e[j].nxt)
				{
					int to=e[j].to;
					if(value[to]<=100000)
					{
						if(!tr[bh[i]].sum[value[to]])
							tr[bh[i]].insert(tr[bh[i]].root,value[to]);
						++tr[bh[i]].sum[value[to]];
					}
				}
				ans[i]=tr[bh[i]].query();
			}
		}
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;++i)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp==2)
			{
				int x;
				scanf("%d",&x);
				if(num[x]>base)printf("%d\n",ans[x]);
				else
				{
					int now=0;
					for(int j=Head[x];j;j=e[j].nxt)
					{
						int to=e[j].to;
						if(value[to]<=100000)usd[value[to]]=true;
					}
					for(int j=0;;++j)
						if(!usd[j])
						{
							printf("%d\n",j);
							break;
						}
					for(int j=Head[x];j;j=e[j].nxt)
					{
						int to=e[j].to;
						if(value[to]<=100000)usd[value[to]]=false;
					}
				}
			}
			else
			{
				int x,y;
				scanf("%d%d",&x,&y);
				for(auto now=v[x].begin();now!=v[x].end();++now)
				{
					int tmpp=*now;
					if(value[x]<=100000)
					{
						--tr[bh[tmpp]].numm[value[x]];
						if(!tr[bh[tmpp]].numm[value[x]])tr[bh[tmpp]].del(tr[bh[tmpp]].root,value[x]);
					} 
					if(y<=100000)
					{
						if(!tr[bh[tmpp]].numm[value[x]])tr[bh[tmpp]].insert(tr[bh[tmpp]].root,value[x]);
						++tr[bh[tmpp]].numm[y];
					} 
					ans[tmpp]=tr[bh[tmpp]].query();
				}
				value[x]=y;
			}
		}
		for(int i=1;i<=tot;++i)T[i].clear();
		for(int i=1;i<=n;++i)v[i].clear();
		for(int i=1;i<=totnum;++i)
		{
			memset(tr[i].sum,0,sizeof(tr[i].sum));
			memset(tr[i].numm,0,sizeof(tr[i].numm));
			tr[i].root=tr[i].build(-INF);
			T[tr[i].root].son[1]=tr[i].build(INF);
			tr[i].push_up(tr[i].root);
		}
	}
	return 0;
}
