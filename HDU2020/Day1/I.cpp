#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define lson m+1,r,rt<<1|1
using namespace std;
struct point
{
	int a,p;
}d[50005];	
bool cmp1(point x,point y)
{
	return x.a<y.a;
}
int Min[50005*4];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		Min[rt]=d[l].p;
		pos[rt]=l;
		return;
	}
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
	if(Min[rt]==Min[rt<<1])pos[rt]=pos[rt<<1];
	if(Min[rt]==Min[rt<<1|1])pos[rt]=pos[rt<<1|1];
}
int nowl,nowr,m;
int querypos(int l,int r,int rt)
{
	if(nowl>=l&&r<=nowr)return pos[rt];
	int re=2147483647,rep;
	int m=(l+r)>>1;
	if(l<=m)
	{
		if(d[query(lson)].p<=re)
		{
			re=d[query(lson)].p;
			rep=pos[rt<<1];
		}
	}
	if(r>m)
	{
		if(d[query(lson)].p<=re)
		{
			re=d[query(lson)].p;
			rep=pos[rt<<1];
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&d[i].p,&d[i].a);
		sort(d+1,d+1+n,cmp1);
	}
	return 0;
}
