#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n,m;
long long sum[4000005];
void add(int l,int r,int rt,int pos,long long k)
{
	if(l==r)
	{
		sum[rt]=k;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)add(lson,pos,k);
	else add(rson,pos,k);
	sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	long long re=0;
	if(m>=nowl)re=max(query(lson,nowl,nowr),re);
	if(m<nowr)re=max(query(rson,nowl,nowr),re);
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		long long y;
		scanf("%d%lld",&x,&y);
		long long now=query(1,1000000,1,max(1,x-m),min(1000000,x+m));
		ans=max(ans,now+y);
		add(1,1000000,1,x,now+y);
	}
	cout<<ans;
	return 0;
}
