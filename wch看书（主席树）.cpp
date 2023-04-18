#include<bits/stdc++.h>
using namespace std;
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
int a[200005],ans[200005],last[200005],now[200005];
struct node
{
	int l,r,sum;
}T[8000005];
int cnt,root[200005];
int build(int l,int r,int node,int pos)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)++T[node].sum;
	else
	{
		int m=(l+r)>>1;
		if(m>=pos)T[node].l=build(l,m,T[node].l,pos);
		else T[node].r=build(m+1,r,T[node].r,pos);
		T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	}
	return node;
}
int query(int l,int r,int node,int nowl,int nowr)
{
	if(l>r)return 0;
	if(l>=nowl&&nowr>=r)return T[node].sum;
	int re=0,m=(l+r)>>1;
	if(m>=nowl)re+=query(l,m,T[node].l,nowl,nowr);
	if(m<nowr)re+=query(m+1,r,T[node].r,nowl,nowr);
	return re;
}
bool usd[100005];
int main()
{
	int n=read(),num=0; 
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		last[i]=now[a[i]];
		now[a[i]]=i;
		if(!usd[a[i]])++num;
		usd[a[i]]=true;
	}
	for(int i=1;i<=n;++i)root[i]=build(0,n,root[i-1],last[i]);
	for(int i=1;i<=n;++i)
	{
		int rr=i-1,ll=last[i];
		if(!ll)continue;
		int t1=query(0,n,root[rr],0,ll);
		int t2=query(0,n,root[ll],0,ll);
		++ans[1];
		--ans[t1-t2+1];
	}
	for(int i=1;i<=n;++i)ans[i]+=ans[i-1];
	int q=read();
	while(q--)
	{
		int t=read();
		printf("%d ",ans[t]+num);
	}
	return 0;
}
