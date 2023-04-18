#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long p;
int n,m;
long long sum[400005],Min[400005],col1[400005],col2[400005];
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
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
}
void push_col(int l,int r,int rt)
{
	if(col2[rt]!=1||col1[rt])
	{
		int m=(l+r)>>1;
		sum[rt<<1]=((sum[rt<<1]*col2[rt])%p+(m-l+1)*col1[rt]%p)%p;
		sum[rt<<1|1]=((sum[rt<<1|1]*col2[rt])%p+(r-m)*col1[rt]%p)%p;
		col2[rt<<1]=(col2[rt<<1]*col2[rt])%p;
		col2[rt<<1|1]=(col2[rt<<1|1]*col2[rt])%p;
		col1[rt<<1]=(col1[rt<<1]*col2[rt]%p+col1[rt])%p;
		col1[rt<<1|1]=(col1[rt<<1|1]*col2[rt]%p+col1[rt])%p;
		col2[rt]=1;
		col1[rt]=0;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c,long long d)
{
	if(l>=nowl&&r<=nowr)
	{
		sum[rt]=((sum[rt]*d)%p+(r-l+1)*c%p)%p;
		col2[rt]=(col2[rt]*d)%p;
		col1[rt]=(col1[rt]*d+c)%p;
		return;
	}
	int m=(l+r)>>1;
	if(col2[rt]!=1||col1[rt])
		push_col(l,r,rt);
	if(m>=nowl)
		modify(lson,nowl,nowr,c,d);
	if(m<nowr)
		modify(rson,nowl,nowr,c,d);
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
		return sum[rt];
	int m=(l+r)>>1;
	long long re=0;
	push_col(l,r,rt);
	if(m>=nowl)
		re=(re+query(lson,nowl,nowr))%p; 
	if(m<nowr)
		re=(re+query(rson,nowl,nowr))%p;
	return re; 
}
int main()
{
	scanf("%d%d%lld",&n,&m,&p);	 
	build(1,n,1);
	for(int i=1;i<=400000;++i)
		col2[i]=1;
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			long long k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,n,1,x,y,0,k);
		}
		else if(t==2)
		{
			int x,y;
			long long k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,n,1,x,y,k,1);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,1,x,y)%p); 
		}
	}
	return 0;
}
