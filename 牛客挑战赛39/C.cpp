#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=111546435;
int n,m;
long long sum[200005<<2],col1[200005<<2],col2[200005<<2];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		sum[rt]%=mod;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	col2[rt<<1]=(col2[rt<<1]+col2[rt])%mod;
	col2[rt<<1|1]=(col2[rt<<1|1]+col2[rt])%mod;
	col1[rt<<1]=(col1[rt<<1]+col1[rt])%mod;
	col1[rt<<1|1]=(col1[rt<<1|1]+(m-l+1)*col2[rt]%mod+col1[rt])%mod;
	sum[rt<<1]=(sum[rt<<1]+col1[rt]*(m-l+1)%mod+(col2[rt]*(m-l+1)*(m-l)/2)%mod)%mod;
	sum[rt<<1|1]=(sum[rt<<1|1]+col1[rt]*(r-m)%mod+(col2[rt]*(r-m)*(r+m+1-2*l)/2)%mod)%mod;
	col1[rt]=col2[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,long long val,long long d)
{
	val%=mod;
	d%=mod;
	if(l>=nowl&&r<=nowr)
	{
		col1[rt]=(col1[rt]+val)%mod;
		col2[rt]=(col2[rt]+d)%mod;
		sum[rt]=(sum[rt]+val*(r-l+1)%mod+(d*(r-l+1)*(r-l)/2)%mod)%mod;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(m>=nowl)modify(lson,nowl,nowr,val,d);
	if(m<nowr)modify(rson,nowl,nowr,val+(m-l+1)*d,d);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	long long re=0;
	push_col(l,r,rt);
	if(m>=nowl)re=(re+query(lson,nowl,nowr))%mod;
	if(m<nowr)re=(re+query(rson,nowl,nowr))%mod;
	return re;
}
int main()
{
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r;
			long long val,d;
			scanf("%d%d%lld%lld",&l,&r,&val,&d);
			modify(1,n,1,l,r,val,d);
		}
		else
		{
			int l,r;
			long long p;
			scanf("%d%d%lld",&l,&r,&p);
			printf("%lld\n",query(1,n,1,l,r)%p);
		}
	}
	return 0;
}
