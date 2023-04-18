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
long long anss;
bool usd[100005];
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
long long t[3],summ[3],dis[100005];
void getdis(int now,int pre)
{
	++t[dis[now]];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		dis[to]=(dis[now]+e[i].v)%3;
		getdis(to,now);
	}
}
long long calc(int now)
{
	long long re=0;
	for(int i=0;i<3;++i)t[i]=summ[i]=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to])continue;
		for(int j=0;j<3;++j)t[j]=0;
		dis[to]=e[i].v%3;
		getdis(to,now);	
		re+=summ[0]*t[0]+summ[1]*t[2]+summ[2]*t[1]+t[0];
		for(int j=0;j<3;++j)summ[j]+=t[j];
	}
	return re*2;
}
void solve(int now)
{
	usd[now]=true;
	anss+=calc(now);
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
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{ 
	n=read();
//	m=read();
	for(int i=1;i<n;++i)
	{
		int x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
//	for(int i=1;i<=m;++i)q[i]=read();	
	maxp[rt]=sum=n;
	getrt(1,0);
	solve(rt);
	anss+=n;
	long long fm=(long long)n*n;
	long long gcdd=gcd(fm,anss);
	cout<<anss/gcdd<<'/'<<fm/gcdd<<endl;
	return 0;
}
