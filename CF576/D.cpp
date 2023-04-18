#include<bits/stdc++.h>
#define N 2000005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
map<int,int>mm;
int m,Min[N*4],tot,col[N*4];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		mm[++tot]=rt;
		scanf("%d",&Min[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void push_col(int l,int r,int rt)
{
	if(l==r)
	{
		if(col[rt]>=Min[rt])
			Min[rt]=col[rt];
		return;
	}
	if(!col[rt])
	{
		col[rt<<1]=col[rt];
		col[rt<<1|1]=col[rt];
		col[rt]=0;
	}
}
void gaoshi(int l,int r,int rt)
{
	push_col(l,r,rt);
	if(l==r)
		return;
	int m=(l+r)>>1;
	gaoshi(lson);
	gaoshi(rson);
}
void modify1(int l,int r,int rt,int now,int k)
{
	if(l==r)
	{
		Min[rt]=k;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=now)
		modify1(lson,now,k);
	else
		modify1(rson,now,k);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void modify2(int l,int r,int rt,int k)
{
	if(l==r)
	{
		if(Min[rt]<k)
			Min[rt]=k;
		return;
	}
	if(col[rt]>=k)
		return;
	if(Min[rt]>=k)
		return;
	push_col(l,r,rt);
	int m=(l+r)>>1;
	modify2(lson,k);
	modify2(rson,k);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int main()
{
	int n;
	scanf("%d",&n);	
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			modify1(1,n,1,x,y);
		}
		else
		{
			int x;
			scanf("%d",&x);
			modify2(1,n,1,x);
		}
	}
	gaoshi(1,n,1);
	for(int i=1;i<=n;++i)
		printf("%d ",Min[mm[i]]);
	return 0;
}
