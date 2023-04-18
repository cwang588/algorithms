#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int head[10005];
int dis[10005];
struct edge
{
	int from,to,value,next;
}e[500005];
int cnt;
bool usd[10005];
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i) 
	{
		++cnt;
		scanf("%d%d%d",&e[cnt].from,&e[cnt].to,&e[cnt].value);
		e[cnt].next=head[e[cnt].from];
		head[e[cnt].from]=cnt;
	}
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].value)
					dis[e[i].to]=dis[e[i].from]+e[i].value;
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",dis[i]);
	return 0;
}
