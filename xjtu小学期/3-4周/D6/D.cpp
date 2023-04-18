#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1
using namespace std;
struct qj
{
	int l,r,ll,rr;
}q[200005];
set<int>s;
map<int>m;
int sum[800005],col[800005],m;
void push_col(int rt)
{
	if(col[rt])
	{
		col[rt<<1]=col[rt<<1]=col[rt];
		col[rt]=0;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,int c)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=c;
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if(m>=nowl)
		modify(lson,nowl,nowr,c);
	if(m<nowr)
		modify(rson,nowl,nowr,c);
}
int main()
{
	int n,qq;
	scanf("%d%d",&n,&qq);
	for(int i=1;i<=qq;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		s.insert(q[i].l);
		s.insert(q[i].r);
	}
	int now=1;
	while(!s.empty())
	{
		iterator it=s.begin();
		map[*it]=now;
		++now;
		s.erase(it);
	}
	for(int i=1;i<=qq;++i)
	{
		q[i].ll=m[q[i].l];
		q[i].rr=m[q[i].r];
	}
	for(int i=1;i<=800000;++i)
		push_col(i);
	int ans=1,last=-1;
	dfs()
	return 0;
}
