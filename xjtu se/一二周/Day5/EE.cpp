#include<bits/stdc++.h>
using namespace std;
struct query
{
	int l,r,id,ans;
}q[300005];
vector<int>v;
int n,m;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int sum[300005],a[300005],b[300005],last[300005];
int lowbit(int x)
{
	return x&(-x);
}
int qq(int x)
{
	int re=0;
	while(x)
	{
		re^=sum[x];
		x-=lowbit(x);
	}
	return re;
}
void add(int x,int y)
{
	while(x<=n)
	{
		sum[x]^=y;
		x+=lowbit(x);
	} 
}
bool cmp(query a,query b)
{
	return a.r<b.r;
}
bool cmpp(query a,query b)
{
	return a.id<b.id;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=b[i-1]^a[i],v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	int now=1;
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=n;++i)
	{
		int col=getid(a[i]);
		if(last[col])add(last[col],a[i]);
		add(i,a[i]);
		last[col]=i;
		while(i==q[now].r)
		{
			q[now].ans=qq(q[now].r)^qq(q[now].l-1)^b[q[now].r]^b[q[now].l-1];
			++now;
		}
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
