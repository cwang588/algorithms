#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
long long dis[100005];
bool used[100005];
int cnt;
struct edge
{
	int from,to,next;
	long long v;
}e[500005];
int head[100005];
void add(int x,int y,long long z)
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
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=s;++i)
	{
		int tep;
		scanf("%d",&tep);
		add(0,tep,0);
		add(tep,0,0);
	}
	for(int i=1;i<=t;++i)
	{
		int tep;
		scanf("%d",&tep);
		add(tep,n+1,0);
		add(n+1,tep,0);
	}
	for(int i=1;i<=m;++i)
	{
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=n+1;++i)
		dis[i]=INF;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
					dis[e[i].to]=dis[e[i].from]+e[i].v;
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	if(dis[n+1]!=INF)
		printf("%lld",dis[n+1]);
	else
		printf("-1");
	return 0;
}
