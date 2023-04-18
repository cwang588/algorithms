#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
int dis[200005];
bool used[200005];
int cnt;
struct edge
{
	int from,to,v,next;
}e[1000005];
int head[200005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	for(int i=1;i<=n;++i)
		dis[i]=(i==1)?0:INF;
	x.push(make_pair(0,1));
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
	bool ky=true;
	for(int i=1;i<=n;++i)
		if(dis[i]==INF)
		{
			ky=false;
			break;
		}
	if(!ky)
		printf("No");
	else
	{
		printf("Yes\n");
		for(int i=1;i<=n;++i)
			printf("%d ",dis[i]);
	}
	return 0;
}
