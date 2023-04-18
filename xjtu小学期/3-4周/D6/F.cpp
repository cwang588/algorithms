#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int Min[800005],Max[800005],ans[800005],m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		int t;
		scanf("%d",&t);
		Min[rt]=Max[rt]=t;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	ans[rt]=max(ans[rt<<1],ans[rt<<1|1]);
	ans[rt]=max(ans[rt],Max[rt<<1|1]-Min[rt<<1]);
}
int querymax(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
		return Max[rt];
	int m=(l+r)>>1,re=0;
	if(nowl<=m)
		re=max(re,querymax(lson,nowl,nowr));
	if(nowr>m)
		re=max(re,querymax(rson,nowl,nowr));
	return re;
}
int querymin(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
		return Min[rt];
	int m=(l+r)>>1,re=999999999;
	if(nowl<=m)
		re=min(re,querymin(lson,nowl,nowr));
	if(nowr>m)
		re=min(re,querymin(rson,nowl,nowr));
	return re;
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
	{
		int m=(l+r)>>1,re=0;
		int MMin=querymin(lson,l,m);
		int MMax=querymax(rson,m+1,r);
		re=MMax-MMin;		
		return max(ans[rt],re);
	}
	int m=(l+r)>>1,re=0;
	if(nowl<=m)
		re=max(re,query(lson,nowl,nowr));
	if(nowr>m)
		re=max(re,query(rson,nowl,nowr));
	return re;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	memset(Min,127,sizeof(Min));
	build(1,n,1);
	for(int i=1;i<=q;++i)
	{
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		int Ans=query(1,n,1,ll,rr),mid=(ll+rr)>>1;
		int MMin=querymin(1,n,1,ll,mid);
		int MMax=querymax(1,n,1,mid+1,rr);
		Ans=max(Ans,MMax-MMin);
		printf("%d\n",Ans);
	}
	return 0;
}
