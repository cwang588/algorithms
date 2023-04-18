#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
int dis[100005];
bool used[100005];
int cnt;
struct edge
{
	int from,to,v,next;
}e[500005];
int head[100005];
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		++cnt;
		scanf("%d%d%d",&e[cnt].from,&e[cnt].to,&e[cnt].v);
		e[cnt].next=head[e[cnt].from];
		head[e[cnt].from]=cnt;
	}
	for(int i=1;i<=n;++i)
		dis[i]=(i==s)?0:INF;
	x.push(make_pair(0,s));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
					dis[e[i].to]=dis[e[i].from]+e[i].v;
				x.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",dis[i]);
	return 0;
}
