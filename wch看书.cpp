#include<bits/stdc++.h>
using namespace std;
int a[100005],sum[100005],n,b[100005],now[100005],last[100005],ans[100005];
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
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
bool usd[100005];
int main()
{
	int q,num=0;	
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(!usd[a[i]])++num;
		usd[a[i]]=true;
	}
	q=read();
	for(int i=1;i<=q;++i)b[i]=read();
	for(int i=1;i<=n;++i)
	{
		int col=a[i];
		if(now[col])add(now[col],-1);
		add(i,1);
		now[col]=i;
		if(last[col])
		{
			int t=query(i-1)-query(last[col]);
			++ans[1];
			--ans[t+1];
		}
		last[col]=i;
	}
	for(int i=1;i<=n;++i)
		ans[i]+=ans[i-1];
	for(int i=1;i<=q;++i)printf("%d ",ans[b[i]]+num);	
	return 0;
}
