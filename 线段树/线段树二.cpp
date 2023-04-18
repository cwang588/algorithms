#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=1e5+6;
int n,m,p;
long long sum[N*4],col1[N*4],col2[N*4];
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
		sum[rt<<1]=((sum[rt<<1]*col2[rt])%p+((m-l+1)*col1[rt])%p)%p;
		sum[rt<<1|1]=((sum[rt<<1|1]*col2[rt])%p+((r-m)*col1[rt])%p)%p;
		col2[rt<<1]=(col2[rt<<1]*col2[rt])%p;
		col2[rt<<1|1]=(col2[rt<<1|1]*col2[rt])%p;
		col1[rt<<1]=(col1[rt<<1]*col2[rt]+col1[rt])%p;
		col1[rt<<1|1]=(col1[rt<<1|1]*col2[rt]+col1[rt])%p;
		col1[rt]=0;
		col2[rt]=1;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c,long long d)
{
	if(nowl<=l&&nowr>=r)
	{
		sum[rt]=((sum[rt]*d)%p+(r-l+1)*c%p)%p;
		col2[rt]=(col2[rt]*d)%p;
		col1[rt]=(col1[rt]*d+c)%p;
		return;
	}
	if(col2[rt]!=1 || col1[rt]!=0)
		push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)
		modify(lson,nowl,nowr,c,d);
	if(m<nowr)
		modify(rson,nowl,nowr,c,d);
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl<=l&&nowr>=r)
		return sum[rt]%p;
	push_col(l,r,rt);
	int m=(l+r)>>1;
	long long ans=0;
	if(nowl<=m)
		ans=(ans+query(lson,nowl,nowr))%p;
	if(m<nowr)
		ans=(ans+query(rson,nowl,nowr))%p;
	return ans%p;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);	
	build(1,n,1);
	for(int i=1;i<=n*4;++i)
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
