#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> > > q;
int head[3005];
int dis[3005];
bool usd[3005];
int p[3005];
int cnt;
struct edge
{
	short to,from,next;
}e[5000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(p[i]>p[j])
			{
				++cnt;
				e[cnt].from=i;
				e[cnt].to=j;
				e[cnt].next=head[i];
				head[i]=cnt;
			}
	for(int i=1;i<=n;++i)
		dis[i]=0;
	dis[1]=p[1];
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]<(dis[e[i].from]^p[e[i].to]))
					dis[e[i].to]=dis[e[i].from]^p[e[i].to];
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	if(dis[n])
		printf("%d",dis[n]);	
	else
		printf("-1");
	return 0;
}
