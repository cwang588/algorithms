#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=2000005;
int n,m;
int Max[N*4];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		cin>>Max[rt];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return Max[rt];
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re=max(re,query(lson,nowl,nowr));
	if(m<nowr)re=max(re,query(rson,nowl,nowr));
	return re;
}
void modify(int l,int r,int rt,int pos,int k)
{
	if(l==r)
	{
		Max[rt]=k;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k);
	else modify(rson,pos,k);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		build(1,n,1);
		for(int i=1;i<=m;++i)
		{
			char t;
			int x,y;
			cin>>t>>x>>y;
			if(t=='Q')printf("%d\n",query(1,n,1,x,y));
			else modify(1,n,1,x,y);
		}
	}
	return 0;
}
