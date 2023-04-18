#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long p;
int m;
struct node
{
	long long sum,col1,col2;
	node()
	{
		col1=1;
	}
}T[400005];
void update(int rt)
{
	T[rt].sum=(T[rt<<1].sum+T[rt<<1|1].sum)%p;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		cin>>T[rt].sum;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void push_col(int l,int r,int rt)
{
	if(T[rt].col2||T[rt].col1!=1)
	{
		int m=(l+r)>>1;
		T[rt<<1].sum=((T[rt<<1].sum*T[rt].col1)%p+((m-l+1)*T[rt].col2)%p)%p;
		T[rt<<1|1].sum=((T[rt<<1|1].sum*T[rt].col1)%p+((r-m)*T[rt].col2)%p)%p;
		T[rt<<1].col1=(T[rt<<1].col1*T[rt].col1)%p;
		T[rt<<1|1].col1=(T[rt<<1|1].col1*T[rt].col1)%p;
		T[rt<<1].col2=(T[rt<<1].col2*T[rt].col1+T[rt].col2)%p;
		T[rt<<1|1].col2=(T[rt<<1|1].col2*T[rt].col1+T[rt].col2)%p;
		T[rt].col2=0;
		T[rt].col1=1;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c,long long d)
{
	if(l>=nowl&&nowr>=r)
	{
		T[rt].sum=((T[rt].sum*d)%p+(r-l+1)*c%p)%p;
		T[rt].col1=(T[rt].col1*d)%p;
		T[rt].col2=(T[rt].col2*d+c)%p;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(nowl<=m)modify(lson,nowl,nowr,c,d);
	if(nowr>m)modify(rson,nowl,nowr,c,d);
	update(rt);
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl<=l&&r<=nowr)return T[rt].sum%p;
	int m=(l+r)>>1;
	push_col(l,r,rt);
	long long re=0;
	if(nowl<=m)re=(re+query(lson,nowl,nowr))%p;
	if(nowr>m)re=(re+query(rson,nowl,nowr))%p;
	return re;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n>>p;
	build(1,n,1);
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		int t;
		cin>>t;
		if(t==2)
		{
			int ll,rr;
			long long c;
			cin>>ll>>rr>>c;
			c%=p;
			modify(1,n,1,ll,rr,c,1);
		}
		else if(t==1)
		{
			int ll,rr;
			long long d;
			cin>>ll>>rr>>d;
			d%=p;
			modify(1,n,1,ll,rr,0,d);
		}
		else 
		{
			int ll,rr;
			cin>>ll>>rr;
			printf("%lld\n",query(1,n,1,ll,rr)%p);
		}
	}
	return 0;
}
