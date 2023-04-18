#include<bits/stdc++.h>
using namespace std;
struct st
{
	int height,id,h;
	long long v;
}a[200005];
bool cmp(st a,st b)
{
	return a.height<b.height;
}
bool cmp1(st a,st b)
{
	return a.id<b.id;
}
int n;
long long sum[200005];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int pos,long long x)
{
	while(pos<=n)
	{
		if(sum[pos]<x)
			sum[pos]=x;
		pos+=lowbit(pos);
	}
}
inline long long query(int pos)
{
	long long re=0;
	while(pos)
	{
		if(re<sum[pos])
			re=sum[pos];
		pos-=lowbit(pos);
	}
	return re;
}
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)
	{
		a[i].id=i;
		scanf("%d",&a[i].height);
	}
	for(register int i=1;i<=n;++i)
		scanf("%lld",&a[i].v);
	sort(a+1,a+1+n,cmp);
	int now=0;
	for(register int i=1;i<=n;++i)
	{
		if(a[i].height>a[i-1].height)
			++now;
		a[i].h=now;
	}
	sort(a+1,a+1+n,cmp1);
	long long ans=0;
	for(register int i=1;i<=n;++i)
	{
		int hh=a[i].h;
		long long t=query(hh)+a[i].v;
		if(ans<t)
			ans=t;
		modify(hh,t);
	}
	printf("%lld",ans);
	return 0;
}
