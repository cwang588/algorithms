#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define INF 1e8
using namespace std;
queue<int>q;
int head[2005];
int tu[2005][2005];
int cnt;
int a[500005],b[500005],c[500005];
int sum[2005]; 
bool usd[2005];
int dis[2005];
bool tt[2005][2005];
struct edge
{
	int from,to,value,next;
}e[500005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		c[i]=INF;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			tu[i][j]=INF;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		tu[a[i]][b[i]]=min(tu[a[i]][b[i]],c[i]);
	}
	for(int i=1;i<=m;++i)
		if(tu[a[i]][b[i]]==c[i]&&!tt[a[i]][b[i]])
		{
			add(a[i],b[i],c[i]);
			tt[a[i]][b[i]]=true;
		}
	for(int i=2;i<=n;++i)
		dis[i]=INF;
	sum[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		usd[now]=false;
		if(now==n)
			continue;
		for(int i=head[now];i;i=e[i].next)
		{
			if(dis[e[i].to]==dis[e[i].from]+e[i].value)
				sum[e[i].to]+=sum[e[i].from];
			if(dis[e[i].to]>dis[e[i].from]+e[i].value)
			{
				dis[e[i].to]=dis[e[i].from]+e[i].value;
				sum[e[i].to]=sum[e[i].from];
			}
			if(sum[e[i].to]&&!usd[e[i].to])
			{
				usd[e[i].to]=true;
				q.push(e[i].to);
			}
		}
		sum[now]=0;
	}
	if(!sum[n])
		return !printf("No answer");
	else
		return !printf("%d %d",dis[n],sum[n]);
	return 0;
}
