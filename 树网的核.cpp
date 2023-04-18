#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,value,next;
}e[605];
int tu[305][305];
int head[305],cnt,d1,d2;
int dis1[305],dis2[305];
int fa[305];
int Max=-1,ans=99999999;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int road[305];
bool usd[305];
void dfs1(int now,int dfn)
{
	usd[now]=true;
	dis1[now]=dfn;
	for(int i=head[now];i;i=e[i].next)
		if(!usd[e[i].to])
			dfs1(e[i].to,dfn+e[i].value);
}
void dfs2(int now,int dfn)
{
	usd[now]=true;
	dis2[now]=dfn;
	for(int i=head[now];i;i=e[i].next)
		if(!usd[e[i].to])
		{
			dfs2(e[i].to,dfn+e[i].value);
			fa[e[i].to]=now;
		}
}
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			tu[i][j]=99999999;
	for(int i=1;i<n;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		tu[a][b]=tu[b][a]=c;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
	dfs1(1,0);
	int M=-1;
	for(int i=2;i<=n;++i)
		if(dis1[i]>M)
		{
			M=dis1[i];
			d1=i;
		}
	for(int i=1;i<=n;++i)
		usd[i]=false;
	dfs2(d1,0);
	M=-1;
	for(int i=1;i<=n;++i)
		if(dis2[i]>M&&i!=d1)
		{
			M=dis2[i];
			d2=i;
		}
	for(int i=1;i<=n;++i)
		usd[i]=false;	
	int fq=d2,j=1;
	road[1]=d2;
	while(fq!=d1)
	{
		fq=fa[fq];
		road[++j]=fq;
	}
	for(int i=1;i<=j;++i)
	{
		Max=-1;
		for(int p=1;p<=n;++p)
			usd[p]=false;
		int endd=i,disnow=0;
		usd[road[i]]=true;
		for(int k=i+1;k<=j;++k)
		{
			disnow+=tu[road[k-1]][road[k]];
			if(disnow>s)
				break;
			endd=k;
			usd[road[k]]=true;
		}
		for(int k=1;k<=n;++k)
			if(!usd[k])
			{
				int Min=9999999;
				for(int o=i;o<=endd;++o)
					Min=min(Min,tu[k][road[o]]);
				Max=max(Max,Min);
			}
		ans=min(ans,Max);
	}
	printf("%d",ans);
	return 0; 
}
