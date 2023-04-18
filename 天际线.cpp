#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct node
{
	int l,r,sum;
}T[40005];
struct fz
{
	int l,r,h;
}f[10005];
int n,m;
int hh[10005];
bool cmp(fz a,fz b)
{
	return a.h<b.h;
}
void build(int l,int r,int rt)
{
	T[rt].l=l;
	T[rt].r=r;
	T[rt].sum=0;
	if(l==r)return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void modify(int l,int r,int rt,int nowl,int nowr,int c)
{
	if(l>=nowl&&r<=nowr)
	{
		T[rt].sum=max(T[rt].sum,c);
		return;
	}
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,c);
	if(m<nowr)modify(rson,nowl,nowr,c);
}
void push_down(int rt)
{
	if(T[rt].l==T[rt].r)
	{
		hh[T[rt].l]=T[rt].sum;
		return;
	}
	T[rt<<1].sum=max(T[rt<<1].sum,T[rt].sum);
	T[rt<<1|1].sum=max(T[rt<<1|1].sum,T[rt].sum);
	T[rt].sum=0;
}
queue<int>q;
int main()
{
	int l,r,h;
	cin>>l>>r>>h;
	while(l)
	{
		++n;
		f[n].l=l;	
		f[n].r=h;	
		f[n].h=r;	
		cin>>l>>r>>h;
	}
//	sort(f+1,f+1+n,cmp);
	build(1,10000,1);
	for(int i=1;i<=n;++i)modify(1,10000,1,f[i].l,f[i].r,f[i].h);
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		push_down(now);
		if(T[now].l!=T[now].r)
		{
			q.push(now<<1);
			q.push(now<<1|1);
		}
	}
	int cnt=0;
	for(int i=1;i<=10000;++i)
		if(hh[i]!=hh[i-1])
		{
			if(hh[i]>hh[i-1])printf("%d %d ",i,hh[i]);
			else printf("%d %d ",i-1,hh[i]);
		}
	return 0;
}
