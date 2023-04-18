// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define maxn 1000008
using namespace std;
struct node{unsigned int l,r,sum;}T[maxn*40];
unsigned int a[maxn],root[maxn],last[maxn],t[maxn],cnt;
unsigned int update(unsigned int l,unsigned int r,unsigned int node,unsigned int pos)
{
	T[++cnt]=T[node],
	node=cnt;
	if(l==r)++T[node].sum;
	else
	{
		unsigned int mid=(l+r)>>1;
		if(pos<=mid)T[node].l=update(l,mid,T[node].l,pos);
		else T[node].r=update(mid+1,r,T[node].r,pos);
		T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	}
	return node;
}
unsigned int query(unsigned int l,unsigned int r,unsigned int nowl,unsigned int nowr,unsigned int node)
{
	if(l>r)return 0;
	if(l>=nowl&&r<=nowr)return T[node].sum;
	unsigned int mid=(l+r)>>1,re=0;
	if(nowl<=mid)re+=query(l,mid,nowl,nowr,T[node].l);
	if(nowr>mid)re+=query(mid+1,r,nowl,nowr,T[node].r);
	return re;
}
inline unsigned int read() 
{
    char ch=getchar();
	unsigned int x=0,f=1;
    while('0'>ch||'9'<ch)
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&'9'>=ch) 
	{
        x=x*10+ch-'0',
        ch=getchar();
    } 
	return x*f;
}
inline void write(unsigned int x)
{
     if(0>x) putchar('-'),x=-x;
     if(9<x) write(x/10);
     putchar(x%10+'0');
}
int main()
{
	unsigned int n,m;
	n=read();
	for(register unsigned int i=1;i<=n;++i)
	{
		a[i]=read();
		unsigned int tt=a[i],ttt=t[tt];
		if(ttt)
			last[i]=ttt;
		t[tt]=i;
	}
	for(register unsigned int i=1;i<=n;++i)root[i]=update(0,n,root[i-1],last[i]);
	m=read();
	for(register unsigned int i=1;i<=m;++i)
	{
		unsigned int x,y;
		x=read(),y=read(),
		write(query(0,n,0,x-1,root[y])-query(0,n,0,x-1,root[x-1])),
		putchar('\n');
	}
	return 0;
}
