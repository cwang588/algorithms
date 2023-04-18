#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=1e5+6;
long long sum[N*4],col[N*4];
int n,m;
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
void color(int l,int r,int rt,long long c)
{
	col[rt]+=c;
	sum[rt]+=(r-l+1)*c;
}
void push_col(int l,int r,int rt)
{
	if(col[rt])
	{
		int m=(l+r)>>1;
		color(lson,col[rt]);
		color(rson,col[rt]);
		col[rt]=0;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c)
{
	if(nowl<=l&&r<=nowr)
	{
		color(l,r,rt,c);
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)
		modify(lson,nowl,nowr,c);
	if(m<nowr)
		modify(rson,nowl,nowr,c);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl<=l&&nowr>=r)
		return sum[rt];
	push_col(l,r,rt);
	long long ans=0;
	int m=(l+r)>>1;
	if(m>=nowl)
		ans+=query(lson,nowl,nowr);
	if(m<nowr)
		ans+=query(rson,nowl,nowr);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			long long k; 
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,n,1,x,y,k);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,1,x,y));
		}
	}
	return 0;
} 
