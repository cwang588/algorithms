#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[100005],n,m;
struct node
{
	int l,r,Max,Min;
	node()
	{
		Max=0;
		Min=2147483647;
	}
}T[1000005];
void build(int l,int r,int rt)
{
	T[rt].l=l;
	T[rt].r=r;
	if(l==r)
	{
		if(l<=n)T[rt].Max=T[rt].Min=a[l];
		else if(l<=2*n)T[rt].Max=T[rt].Min=a[l-n];
		else T[rt].Max=T[rt].Min=a[l-2*n];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	T[rt].Max=max(T[rt<<1].Max,T[rt<<1|1].Max);
	T[rt].Min=min(T[rt<<1].Min,T[rt<<1|1].Min);
}
int queryMin(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return T[rt].Min;
	int re=2147483647;
	int m=(l+r)>>1;
	if(nowl<=m)re=min(re,queryMin(lson,nowl,nowr));
	if(m<nowr)re=min(re,queryMin(rson,nowl,nowr));
	return re;
}
int queryMax(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return T[rt].Max;
	int re=0;
	int m=(l+r)>>1;
	if(nowl<=m)re=max(re,queryMax(lson,nowl,nowr));
	if(m<nowr)re=max(re,queryMax(rson,nowl,nowr));
	return re;
}
int queryMaxpos(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(T[rt].Max<k)return 2147483647;
	if(l==r)return l;
	int m=(l+r)>>1;
	int re=2147483647;
	if(nowl<=m)re=min(re,queryMaxpos(lson,nowl,nowr,k));
	if(m<nowr)re=min(re,queryMaxpos(rson,nowl,nowr,k));
	return re;
}
int queryMinpos(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(T[rt].Min*2>=k)return 2147483647;
	if(l==r)return l;
	int m=(l+r)>>1;
	int re=2147483647;
	if(nowl<=m)re=min(re,queryMinpos(lson,nowl,nowr,k));
	if(m<nowr)re=min(re,queryMinpos(rson,nowl,nowr,k));
	return re;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,3*n,1);
	for(int i=1;i<=n;++i)
	{
		int Maxx=queryMax(1,3*n,1,i,i+2*n);
		int Minn=queryMin(1,3*n,1,i,i+2*n);
		if(Minn*2>=Maxx)
		{
			printf("-1\n");
			continue;
		}
		int pos=queryMaxpos(1,3*n,1,i,i+2*n,Maxx);
		printf("%d\n",queryMinpos(1,3*n,1,pos,i+2*n,Maxx)-i);
	}
	return 0;
}
