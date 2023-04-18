#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=40005;
long long sum0[N<<2],sum1[N<<2],sum2[N<<2],sum3[N<<2],sum[N<<2];
int n,m;
void push_up(int l,int r,int rt)
{
	sum0[rt]=max(sum0[rt<<1]+sum0[rt<<1|1],sum0[rt<<1]+sum2[rt<<1|1]);
	sum0[rt]=max(sum0[rt],sum1[rt<<1]+sum0[rt<<1|1]);
	sum1[rt]=max(sum0[rt<<1]+sum1[rt<<1|1],sum0[rt<<1]+sum3[rt<<1|1]);
	sum1[rt]=max(sum1[rt],sum1[rt<<1]+sum1[rt<<1|1]);
	sum2[rt]=max(sum2[rt<<1]+sum0[rt<<1|1],sum3[rt<<1]+sum0[rt<<1|1]);
	sum2[rt]=max(sum2[rt],sum2[rt<<1]+sum2[rt<<1|1]);
	if(r>l+1)
	{
		sum3[rt]=max(sum2[rt<<1]+sum3[rt<<1|1],sum3[rt<<1]+sum1[rt<<1|1]);
		sum3[rt]=max(sum3[rt],sum2[rt<<1]+sum1[rt<<1|1]);
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		sum3[rt]=sum[rt];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(l,r,rt);
}
void modify(int l,int r,int rt,int pos,long long k)
{
	if(l==r)
	{
		sum3[rt]=k;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k);
	else modify(rson,pos,k);
	push_up(l,r,rt);
}
long long tot=0;
void getans()
{
	long long ans=0;
	ans=max(ans,sum0[1]);
	ans=max(ans,sum1[1]);
	ans=max(ans,sum2[1]);
	ans=max(ans,sum3[1]);
	tot+=ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int x;
		long long y;
		scanf("%d%lld",&x,&y);
		modify(1,n,1,x,y);
		getans();
	}
	printf("%lld\n",tot);
	return 0;
}
