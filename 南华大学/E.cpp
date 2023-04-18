#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int head[10005];
int dis1[10005],dis2[10005];
bool usd1[10005],usd2[10005];
int cnt;
struct edge
{
	int to,from,value,next;
}e[500005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	int n,s,E;
	scanf("%d%d%d",&n,&s,&E);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=n;++i)
		dis1[i]=INF;
	dis1[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd1[now])
		{
			usd1[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis1[e[i].to]>dis1[e[i].from]+e[i].value)
					dis1[e[i].to]=dis1[e[i].from]+e[i].value;
				q.push(make_pair(dis1[e[i].to],e[i].to));
			}
		}
	}
	for(int i=1;i<=n;++i)
		dis2[i]=INF;
	dis2[E]=0;
	q.push(make_pair(0,E));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd2[now])
		{
			usd2[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis2[e[i].to]>dis2[e[i].from]+e[i].value)
					dis2[e[i].to]=dis2[e[i].from]+e[i].value;
				q.push(make_pair(dis2[e[i].to],e[i].to));
			}
		}
	}
	int ans=dis1[E];
	int k;
	bool yong=false;
	scanf("%d",&k);
	for(int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(dis1[x]!=INF&&dis2[y]!=INF&&dis1[x]+dis2[y]<ans)
		{
			ans=dis1[x]+dis2[y];
			yong=true;
		}
		if(dis2[x]!=INF&&dis1[y]!=INF&&dis2[x]+dis1[y]<ans)
		{
			ans=dis2[x]+dis1[y];
			yong=true;
		}
	}
	if(yong)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d",ans);
	return 0;
}
