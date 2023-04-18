#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
long long sum[200005];
struct bijiao
{
	int a,b;
}t[200005];
int n;
int lowbit(int x)
{
	return x&(-x);
}
bool cmp(bijiao x,bijiao y)
{
	return x.a>y.a;
}
long long query(int x)
{
	long long re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
void add(int x)
{
	while(x<=n)
	{
		++sum[x];
		x+=lowbit(x);
	}
}
int main()
{
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;++i)
	{
		t[i].a=a[i];
		t[i].b=b[i];
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		long long tt=query(t[i].b);
		ans+=tt;
		add(t[i].b);
	}
	for(int i=1;i<=n;++i)sum[i]=0;
	for(int i=1;i<=n;++i)
	{
		t[i].a=a[i];
		t[i].b=c[i];
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		long long tt=query(t[i].b);
		ans+=tt;
		add(t[i].b);
	}
	for(int i=1;i<=n;++i)sum[i]=0;
	for(int i=1;i<=n;++i)
	{
		t[i].a=c[i];
		t[i].b=b[i];
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		long long tt=query(t[i].b);
		ans+=tt;
		add(t[i].b);
	}
	printf("%lld\n",ans/2);
	return 0;
}
