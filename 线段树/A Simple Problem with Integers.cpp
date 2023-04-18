#include<iostream>
#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n,m;
long long sum[200005*4],col[200005*4];
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	col[rt<<1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	sum[rt<<1]+=col[rt]*(long long)(m-l+1);
	sum[rt<<1|1]+=col[rt]*(long long)(r-m);
	col[rt]=0;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	push_col(l,r,rt);
	long long re=0;
	if(m>=nowl)re+=query(lson,nowl,nowr);
	if(m<nowr)re+=query(rson,nowl,nowr);
	return re;
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]+=k;
		sum[rt]+=k*(long long)(r-l+1);
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(m>=nowl)modify(lson,nowl,nowr,k);
	if(m<nowr)modify(rson,nowl,nowr,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int main()
{
//	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		char t;
		cin>>t;
		if(t=='Q')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,1,x,y));
		}
		else
		{
			int x,y;
			long long z;
			scanf("%d%d%lld",&x,&y,&z);
			modify(1,n,1,x,y,z);
		}
	}
	return 0;
}
