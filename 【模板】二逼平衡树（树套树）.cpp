#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std; 
typedef long long LL;
const int maxm = 2e6+26;
const int maxn = 2e6+15;
struct data{int l,r,v,size,fix,w;}tr[maxm];
int len,root[maxn];
void update(int k){tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;}
void rturn(int &k){int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;tr[t].size=tr[k].size;update(k);k=t;}
void lturn(int &k){int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;tr[t].size=tr[k].size;update(k);k=t;}
void Insert(int &k,int x)                        //插入数x
{
    if(k==0){len++;k=len;tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].fix=rand();return;}
    tr[k].size++;
    if(tr[k].v==x)tr[k].w++;
    else if(x>tr[k].v){Insert(tr[k].r,x);if(tr[tr[k].r].fix<tr[k].fix)lturn(k);}
    else {Insert(tr[k].l,x);if(tr[tr[k].l].fix<tr[k].fix)rturn(k);} 
} 
void Delete(int &k,int x)                        //删除数x
{
    if(k==0) return; 
    if(tr[k].v==x)
    {
        if(tr[k].w>1){tr[k].w--;tr[k].size--;return;}
        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
        else if(tr[tr[k].l].fix<tr[tr[k].r].fix) rturn(k),Delete(k,x);
        else lturn(k),Delete(k,x);
    }
    else if(x>tr[k].v) tr[k].size--,Delete(tr[k].r,x);
    else tr[k].size--,Delete(tr[k].l,x);
}
/*
    查找x的排名
    返回 <= x 的数量,等于x的数有多个,只算一个
*/
int Findrank(int k,int x)                    
{
    if(k==0) return 0;
    if(tr[k].v==x) return tr[tr[k].l].size;
    else if(x>tr[k].v) return tr[tr[k].l].size+tr[k].w+Findrank(tr[k].r,x);
    else return Findrank(tr[k].l,x);
}
int Findkth(int k,int x)                        //查找排名为x的数
{
    if(k==0) return 0;
    if(x<=tr[tr[k].l].size) return Findkth(tr[k].l,x);
    else if(x>tr[tr[k].l].size+tr[k].w) return Findkth(tr[k].r,x-tr[tr[k].l].size-tr[k].w);
    else return tr[k].v;
}
int Findpre(int now,int x)
{
	int pre=-2147483647;
	while(now)
	{
		if(tr[now].v<x)
		{
			pre=tr[now].v;
			now=tr[now].r;
		}
		else now=tr[now].l;
	}
	return pre;
}
int Findnxt(int now,int x)
{
	int nxt=2147483647;
	while(now)
	{
		if(tr[now].v>x)
		{
			nxt=tr[now].v;
			now=tr[now].l;
		}
		else now=tr[now].r;
	}
	return nxt;
}
/*treap*/
int num[100005],n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		Insert(root[rt],num[l]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	for(int i=l;i<=r;++i)Insert(root[rt],num[i]);
}
int queryrank(int l,int r,int rt,int nowl,int nowr,int x)
{
	if(l>=nowl&&r<=nowr)return Findrank(root[rt],x);
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re+=queryrank(lson,nowl,nowr,x);
	if(m<nowr)re+=queryrank(rson,nowl,nowr,x);
	return re;
}
int querykth(int nowl,int nowr,int k)
{
	int l=-2147483647,r=2147483647,re=l;
	while(l<r)
	{
		int m=(l+r)>>1;
		int tmp=queryrank(1,n,1,nowl,nowr,m);
		if(tmp<k)l=m+1,re=m;
		else r=m;
	}
	return l-1;
}
void modify(int l,int r,int rt,int pos,int x)
{
	if(l==r)
	{
		Delete(root[rt],num[pos]);
		Insert(root[rt],x);
		num[pos]=x;
		return;
	}
	int m=(l+r)>>1;
	Delete(root[rt],num[pos]);
	Insert(root[rt],x);
	if(m>=pos)modify(lson,pos,x);
	else modify(rson,pos,x);
}
int querypre(int l,int r,int rt,int nowl,int nowr,int x)
{
	if(l>=nowl&&r<=nowr)return Findpre(root[rt],x);
	int m=(l+r)>>1;
	int re=-2147483647;
	if(m>=nowl)re=max(re,querypre(lson,nowl,nowr,x));
	if(m<nowr)re=max(re,querypre(rson,nowl,nowr,x));
	return re;
}
int querynxt(int l,int r,int rt,int nowl,int nowr,int x)
{
	if(l>=nowl&&r<=nowr)return Findnxt(root[rt],x);
	int m=(l+r)>>1;
	int re=2147483647;
	if(m>=nowl)re=min(re,querynxt(lson,nowl,nowr,x));
	if(m<nowr)re=min(re,querynxt(rson,nowl,nowr,x));
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&num[i]);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",queryrank(1,n,1,l,r,k)+1);
		}
		else if(t==2)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querykth(l,r,k));
		}
		else if(t==3)
		{
			int pos,k;
			scanf("%d%d",&pos,&k);
			modify(1,n,1,pos,k);
		}
		else if(t==4)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querypre(1,n,1,l,r,k));
		}
		else
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",querynxt(1,n,1,l,r,k));
		}
	}
	return 0;
} 
