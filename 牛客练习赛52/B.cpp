#include<bits/stdc++.h>
using namespace std;
struct query
{
	int l,r,id;
	long long ans;
}q[500005];
long long a[500005],sum[500005],last[500005];
int n,m;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,long long num)
{
	if(!x)return;
	while(x<=n)
	{
		sum[x]+=num;
		x+=lowbit(x);
	}
}
long long qq(int x)
{
	long long re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
bool cmp1(query a,query b)
{
	return a.r<b.r;
}
bool cmp2(query a,query b)
{
	return a.id<b.id;
}
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp1);
	int now=1;
	for(int i=1;i<=n;++i)
	{
		int t=last[a[i]];
		if(t)add(t,-a[i]);
		add(i,a[i]);
		last[a[i]]=i;
		while(i==q[now].r)
		{
			q[now].ans=qq(i)-qq(q[now].l-1);
			++now;
		}
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i)printf("%lld\n",q[i].ans);
	return 0;
}
