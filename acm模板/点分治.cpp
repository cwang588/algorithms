#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
struct edge
{
	int from,to,v,nxt;
}e[200005];
int Head[100005],cnt,q[105],rt,maxp[100005],sum,n,m;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int size[100005];
int ans,num,tott;
int dis[100005],len[100005],tep[100005];
bool usd[100005],cd[10000005],cz[10005];
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
void getrt(int now,int pre)
{
	size[now]=1;	
	maxp[now]=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		getrt(to,now);
		size[now]+=size[to];
		maxp[now]=max(maxp[now],size[to]);
	}
	maxp[now]=max(maxp[now],sum-size[now]);
	if(maxp[now]<maxp[rt])rt=now;	
}
void getdis(int now,int pre)
{
	len[++num]=dis[now];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		dis[to]=dis[now]+e[i].v;
		getdis(to,now);
	}
}
void calc(int now)
{
	tott=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to])continue;
		num=0;
		dis[to]=e[i].v;
		getdis(to,now);
		for(int j=1;j<=num;++j)
			for(int k=1;k<=m;++k)
				if(q[k]>=len[j]&&cd[q[k]-len[j]])
					cz[k]=true;
		for(int j=1;j<=num;++j)
		{
			cd[len[j]]=true;
			tep[++tott]=len[j];
		}
	}
	for(int i=1;i<=tott;++i)cd[tep[i]]=false;
}
void solve(int now)
{
	usd[now]=cd[0]=true;
	calc(now);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to])continue;
		sum=size[to];
		maxp[rt=0]=INF;
		getrt(to,0);
		solve(rt);
	}
}
int main()
{ 
	n=read();
	m=read();
	for(int i=1;i<n;++i)
	{
		int x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=m;++i)q[i]=read();	
	maxp[rt]=sum=n;
	getrt(1,0);
	solve(rt);
	for(int i=1;i<=m;++i)
	{
		if(cz[i])printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}
