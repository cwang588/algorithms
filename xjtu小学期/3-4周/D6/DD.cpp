#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int sum[2000005],col[2000005],m,zuo[2000005],you[2000005];
struct qj
{
	int l,r,ll,rr;
}q[200005];
set<int>s;
map<int,int>mm;
void push_col(int l,int r,int rt)
{
	if(col[rt]!=-1)
	{
		sum[rt]=sum[rt<<1]=sum[rt<<1|1]=1;
		col[rt<<1]=col[rt<<1|1]=col[rt];
		zuo[rt<<1]=you[rt<<1]=zuo[rt<<1|1]=you[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,int c)
{
	if(l>=nowl&&r<=nowr)
	{
		sum[rt]=1;
		you[rt]=zuo[rt]=c;
		col[rt]=c;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(m>=nowl)
		modify(lson,nowl,nowr,c);
	if(m<nowr)
		modify(rson,nowl,nowr,c);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	if(you[rt<<1]==zuo[rt<<1|1])
		--sum[rt];
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
		return sum[rt];
	int re=0;
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(m>=nowl)
		re+=(lson,nowl,nowr);
	if(m<nowr)
		re+=(rson,nowl,nowr);
	if(m<nowr&&m>=nowl&&you[rt<<1]==zuo[rt<<1|1])
		--re;
	return re;
}
int main()
{
	int n,qq;
	scanf("%d%d",&n,&qq);
	for(int i=1;i<=2000000;++i)
	{
		sum[i]=1;
		col[i]=-1;
	}
	modify(1,n,1,1,n,0);	
	for(int i=1;i<=qq;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		s.insert(q[i].l);
		s.insert(q[i].r);
	}
	int now=1;
	while(!s.empty())
	{
		set<int>::iterator it=s.begin();
		mm[*it]=now;
		++now;
		s.erase(it);
	}
	for(int i=1;i<=qq;++i)
	{
		q[i].ll=mm[q[i].l];
		q[i].rr=mm[q[i].r];
	}
	for(int i=1;i<=qq;++i)
	{
		modify(1,n,1,q[i].ll,q[i].rr,i);
		printf("%d\n",query(1,n,1,1,n));
	}
	return 0;
}
