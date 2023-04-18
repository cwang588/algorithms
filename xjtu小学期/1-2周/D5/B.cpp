#include<bits/stdc++.h>
using namespace std;
struct human
{
	int gu,id,gg;
}h[100006];
bool cmp1(human a,human b)
{
	return a.gu<b.gu;
}
bool cmp2(human a,human b)
{
	return a.id<b.id;
}
int n;
int sum[100005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	while(x<=n)
	{
		sum[x]=max(sum[x],y);
		x+=lowbit(x);
	}
}
int query(int x)
{
	int re=0;
	while(x)
	{
		re=max(sum[x],re);
		x-=lowbit(x);
	}
	return re;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&h[i].gu);
		h[i].id=i;
	}
	sort(h+1,h+1+n,cmp1);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(h[i].gu==h[i-1].gu)
			h[i].gg=now;
		else
			h[i].gg=++now;
	}
	sort(h+1,h+1+n,cmp2);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int t=query(h[i].gg-1)+1;
		ans=max(ans,t);
		add(h[i].gg,t);
	}
	printf("%d",ans);
	return 0;
}
