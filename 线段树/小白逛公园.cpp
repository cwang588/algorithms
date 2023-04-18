#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=500005;
struct node
{
	long long sum0,sum1,sum2,sum3;
	node()
	{
		sum3=0;
		sum0=sum1=sum2=0;
	}
}T[N<<2];
long long Min[N<<2];
int n,m;
void update(int rt)
{
	T[rt].sum0=max(T[rt<<1|1].sum2,T[rt<<1].sum1);
	T[rt].sum0=max(T[rt].sum0,T[rt<<1].sum1+T[rt<<1|1].sum2);
	T[rt].sum1=max(T[rt<<1|1].sum1,T[rt<<1|1].sum3);
	T[rt].sum1=max(T[rt].sum1,T[rt<<1].sum1+T[rt<<1|1].sum3);
	T[rt].sum2=max(T[rt<<1].sum2,T[rt<<1].sum3);
	T[rt].sum2=max(T[rt].sum2,T[rt<<1].sum3+T[rt<<1|1].sum2);
	T[rt].sum3=T[rt<<1].sum3+T[rt<<1|1].sum3;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&T[rt].sum3);
		Min[rt]=T[rt].sum3;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
	Min[rt]=max(Min[rt<<1],Min[rt<<1|1]);
}
void modify(int l,int r,int rt,int pos,long long k)
{
	if(l==r)
	{
		Min[rt]=T[rt].sum3=k;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k);
	else modify(rson,pos,k);
	update(rt);
	Min[rt]=max(Min[rt<<1],Min[rt<<1|1]);
}
node query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return T[rt];
	int m=(l+r)>>1;
	node re,re1,re2;
	bool ky1=false,ky2=false;
	if(m>=nowl)
	{
		ky1=true;
		re1=query(lson,nowl,nowr);
	}
	if(m<nowr)
	{
		ky2=true;
		re2=query(rson,nowl,nowr);
	}
	if(ky1&&ky2)
	{
		re.sum0=max(re2.sum2,re1.sum1);
		re.sum0=max(re.sum0,re1.sum1+re2.sum2);
		re.sum1=max(re2.sum1,re2.sum3);
		re.sum1=max(re.sum1,re1.sum1+re2.sum3);
		re.sum2=max(re1.sum2,re1.sum3);
		re.sum2=max(re.sum2,re1.sum3+re2.sum2);
		re.sum3=re1.sum3+re2.sum3;
		return re;
	}
	if(ky1)return re1;
	else return re2;
}
long long querymin(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return Min[rt];
	int m=(l+r)>>1;
	long long re=-2147483647;
	if(m>=nowl)re=max(re,querymin(lson,nowl,nowr));
	if(m<nowr)re=max(re,querymin(rson,nowl,nowr));
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			node ans=query(1,n,1,x,y);
			long long anss=-2147483647;
			anss=max(anss,ans.sum0);
			anss=max(anss,ans.sum1);
			anss=max(anss,ans.sum2);
			anss=max(anss,ans.sum3);
			if(anss<=0)anss=querymin(1,n,1,x,y);
			printf("%lld\n",anss);
		}
		else
		{
			int p;
			long long kk;
			scanf("%d%lld",&p,&kk);
			modify(1,n,1,p,kk);
		}
	}
	return 0;
}
