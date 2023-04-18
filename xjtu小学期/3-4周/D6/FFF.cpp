#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

map <int,int> mp;
bitset<200005> book;
struct Node
{
	int l,r;
};
Node e[200005];
int arr[400005],num[200005],col[200005];
int q,n,ln;
inline void update(int rt)
{
	if(num[rt<<1]==num[rt<<1|1]&&num[rt<<1]!=-1) num[rt]=num[rt<<1];
	else num[rt]=-1;
}
void push_col(int l,int r,int rt)
{
	if(col[rt]!=-1)
	{
		int m=(l+r)>>1;
		num[rt<<1]=num[rt<<1|1]=col[rt];
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		num[rt]=0;
		col[rt]=-1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
		if(num[rt]!=-1)
		{
			book.set(num[rt],1);
			return;
		}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl) query(lson,nowl,nowr);
	if(m<nowr) query(rson,nowl,nowr);
}
void modify(int l,int r,int rt,int nowl,int nowr,int c)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=num[rt]=c;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl) modify(lson,nowl,nowr,c);
	if(m<nowr) modify(rson,nowl,nowr,c);
	update(rt);
}
int main()
{
	scanf("%d%d",&n,&q);
	arr[++ln]=n;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&e[i].l,&e[i].r);
		arr[++ln]=e[i].l,arr[++ln]=e[i].r;
	}
	sort(arr+1,arr+ln+1);
	for(int i=1;i<=ln;i++)
	{
		if(arr[i]==arr[i-1]) continue;
		mp[arr[i]]=mp[arr[i-1]]+1;
	}
	n=mp[n];
	for(int i=1;i<=q;i++) e[i].l=mp[e[i].l],e[i].r=mp[e[i].r];
	build(1,n,1);
	modify(1,n,1,1,n,0);
	for(int i=1;i<=q;i++)
	{
		modify(1,n,1,e[i].l,e[i].r,i);
		query(1,n,1,1,n);
		printf("%d\n",book.count());
		book.reset();
	}
	return 0;
}

