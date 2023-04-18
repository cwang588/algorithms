#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=50005;
int n,m;
int lmax[N<<3],rmax[N<<3],totmax[N<<3],col[N<<3],tot[N<<3];
void update(int l,int r,int rt)
{
	int m=(l+r)>>1;
	totmax[rt]=max(totmax[rt<<1],totmax[rt<<1|1]);
	totmax[rt]=max(totmax[rt],rmax[rt<<1]+lmax[rt<<1|1]);
	if(totmax[rt<<1]==m-l+1)lmax[rt]=m-l+1+lmax[rt<<1|1];
	else lmax[rt]=lmax[rt<<1];
	if(totmax[rt<<1|1]==r-m)rmax[rt]=r-m+rmax[rt<<1];
	else rmax[rt]=rmax[rt<<1|1];
	tot[rt]=tot[rt<<1]+tot[rt<<1|1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		lmax[rt]=rmax[rt]=totmax[rt]=tot[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(l,r,rt);
}
void push_col(int l,int r,int rt)
{
	if(!col[rt])return;
	if(col[rt]==1)
	{
		lmax[rt<<1]=rmax[rt<<1]=totmax[rt<<1]=tot[rt<<1]=0;
		lmax[rt<<1|1]=rmax[rt<<1|1]=totmax[rt<<1|1]=tot[rt<<1|1]=0;
		col[rt<<1]=col[rt<<1|1]=1;
	}
	else
	{
		int m=(l+r)>>1;
		lmax[rt<<1]=rmax[rt<<1]=totmax[rt<<1]=tot[rt<<1]=m-l+1;
		lmax[rt<<1|1]=rmax[rt<<1|1]=totmax[rt<<1|1]=tot[rt<<1|1]=r-m;
		col[rt<<1]=col[rt<<1|1]=2;
	}
	col[rt]=0;
}
int Find(int l,int r,int rt)
{
	if(l==r)return l;
	int m=(l+r)>>1;
	push_col(l,r,rt);
	update(l,r,rt);
	if(totmax[rt<<1|1]==r-m)
	{
		if(!tot[rt<<1])return Find(rson);
		return Find(lson);
	}
	else return Find(rson);
}
int query(int l,int r,int rt,int num)
{
	if(l==r)return l;
	push_col(l,r,rt);
	update(l,r,rt);
	int m=(l+r)>>1;
	if(totmax[rt<<1]<num&&totmax[rt<<1|1]<num)
	{
		if(rmax[rt<<1])return Find(lson);
		else return query(rson,num);
	}
	if(totmax[rt<<1]>=num)return query(lson,num);
//	else if(rmax[rt<<1]+lmax[rt<<1|1]<num)return query(rson,num);
	else 
	{
		if(rmax[rt<<1]+lmax[rt<<1|1]>=num)
		{
			if(tot[rt<<1])return Find(lson);
			else query(rson,num);
		}
		else return query(rson,num);
	}
}
void modify1(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=k;
		if(k==1)totmax[rt]=lmax[rt]=rmax[rt]=tot[rt]=0;
		else totmax[rt]=lmax[rt]=rmax[rt]=tot[rt]=r-l+1;
		return;		
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify1(lson,nowl,nowr,k);
	if(m<nowr)modify1(rson,nowl,nowr,k);
	update(l,r,rt);
}
void modify2(int l,int r,int rt,int num)
{
	if(!num)return;
	if(tot[rt]==r-l+1)
	{
		col[rt]=1;
		tot[rt]=lmax[rt]=rmax[rt]=totmax[rt]=0;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(tot[rt<<1]>=num)modify2(lson,num);
	else
	{
		modify2(lson,tot[rt<<1]);
		modify2(rson,num-tot[rt<<1]);
	}
	update(l,r,rt);
}
int main()
{
	//freopen("data.in","r",stdin);
//	freopen("my.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int sum;
			scanf("%d",&sum);
			if(totmax[1]>=sum)
			{
				int pos=query(1,n,1,sum);
				printf("%d\n",pos);
				modify1(1,n,1,pos,pos+sum-1,1);
			}
			else
			{
				printf("0\n");
				if(tot[1]>=sum)modify2(1,n,1,sum);
			}
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			modify1(1,n,1,x,x+y-1,2);
		}
	}
	return 0;
}
