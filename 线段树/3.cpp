#include<bits/stdc++.h>
#define lson l,m,rt>>1
#define rson m+1,rt>>1|1
using namespace std;
long long sum[N*4],Max[N*4],jia[N*4];
int n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		Max[rt]=sum[rt];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt>>1]+sum[rt>>1|1];
	Max[rt]=max(sum[rt>>1],sum[rt>>1|1]);
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c)
{
	if(l>=nowl&&r<=nowr)
	{
		jia[rt]+=c;
		sum[rt]+=c*(r-l+1);
		Max[rt]+=c;
		return;
	}
	int m=(l+r)>>1;
	if(m>=nowl)
		modify(lson,nowl,nowr,c);
	if(m<nowr)
		modify(rson,nowl,nowr,c);
	sum[rt]=sum[rt>>1]+sum[rt>>1|1];
	Max[rt]=max(sum[rt>>1],sum[rt>>1|1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
		{
			long long k;
			cin>>k;
			modify(1,n,1,x,y,k);
		}
	}
	return 0;
}
