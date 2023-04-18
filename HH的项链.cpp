#include<bits/stdc++.h>
using namespace std;
struct query
{
	int l,r,id,ans;
}q[1000005];
int a[1000005],sum[1000005],now[1000005],n;
bool cmp(query a,query b)
{
	return a.r<b.r;
}
bool cmpp(query a,query b)
{
	return a.id<b.id;
}
int lowbit(int x)
{
	return x&(-x);
}
int qq(int x)
{
	int re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x); 
	}
	return re;
}
void add(int x,int num)
{
	while(x<=n)
	{
		sum[x]+=num;
		x+=lowbit(x);
	}
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
	int m; 
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	m=read(); 
	for(int i=1;i<=m;++i)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int pos=1;
	for(int i=1;i<=n;++i)
	{
		int col=a[i];
		if(now[col])add(now[col],-1);
		add(i,1);
		now[col]=i;
		while(i==q[pos].r)
		{
			q[pos].ans=qq(q[pos].r)-qq(q[pos].l-1);
			++pos;
		}
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
