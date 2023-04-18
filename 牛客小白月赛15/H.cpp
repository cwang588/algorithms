#include<bits/stdc++.h>
using namespace std;
const int mod=20180623;
struct A
{
	int l1,l2,r1,r2,ans,x;
}qq[100005];
struct query
{
	int l,r,lw,rw,id,ans,x;
}q[200005];
int a[100005],num[100005];
bool cmp1(query aa,query bb)
{
	return aa.lw==bb.lw?aa.rw<bb.rw:aa.lw<bb.lw;
}
bool cmp2(query aa,query bb)
{
	return aa.id<bb.id;
}
int base;
int main()
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	base=sqrt(n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=Q;++i)
	{
		scanf("%d%d%d%d%d",&qq[i].l1,&qq[i].r1,&qq[i].l2,&qq[i].r2,&qq[i].x);
		if(qq[i].l1>qq[i].r1)
			swap(qq[i].l1,qq[i].r1);
		if(qq[i].l2>qq[i].r2)
			swap(qq[i].l2,qq[i].r2);
		q[i*2-1].l=qq[i].l1;
		q[i*2-1].lw=qq[i].l1/base;
		q[i*2-1].r=qq[i].r1;
		q[i*2-1].rw=qq[i].r1/base;
		q[i*2-1].x=qq[i].x;
		q[i*2-1].id=2*i-1;
		q[i*2].l=qq[i].l2;
		q[i*2].lw=qq[i].l2/base;
		q[i*2].r=qq[i].r2;
		q[i*2].rw=qq[i].r2/base;
		q[i*2].x=qq[i].x;
		q[i*2].id=2*i;
	}
	sort(q+1,q+Q*2+1,cmp1);
	int l=0,r=0;
	for(int i=1;i<=2*Q;++i)
	{
		while(r<q[i].r)
		{
			++r;
			++num[a[r]];
		}
		while(l>q[i].l)
		{
			--l;
			++num[a[l]];
		}
		while(r>q[i].r)
		{
			--num[a[r]];
			--r;
		}
		while(l<q[i].l)
		{
			++num[a[l]];
			++l;
		}
		q[i].ans=num[q[i].x];
	}
	sort(q+1,q+1+2*Q,cmp2);
	for(int i=1;i<=Q;++i)
	{
		qq[i].ans=q[2*i-1].ans*q[2*i].ans%mod;
		printf("%d\n%d\n%d\n",q[2*i-1].ans,q[2*i].ans,qq[i].ans);
	}
	return 0;
}
