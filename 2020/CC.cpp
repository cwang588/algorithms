#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=998244353;
long long sum[200005*4];
long long a[200005];
int n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]*sum[rt<<1|1]%mod;
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	long long re=1;
	if(m>=nowl)re=re*query(lson,nowl,nowr)%mod;
	if(m<nowr)re=re*query(rson,nowl,nowr)%mod;
	return re;
}
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	build(1,n,1);
	long long ans=0;
	for(int i=1;i+k-1<=n;++i)ans=max(ans,query(1,n,1,i,i+k-1));
	printf("%lld\n",ans);
	return 0;
}
