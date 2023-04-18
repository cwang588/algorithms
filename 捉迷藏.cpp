#include<cstdio>
#include<utility>
#include<queue>
#include<algorithm>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
int dis[20005],head[20005];
bool usd[20005];
struct edge
{
	int from,to,value,next;
}e[100005];
int cnt;
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].value=c;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,1);
	}
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	dis[1]=0;
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
				if(dis[e[i].to]>dis[e[i].from]+e[i].value)
					dis[e[i].to]=dis[e[i].from]+e[i].value;
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	int M=-1,num=0,po;
	for(int i=2;i<=n;++i)
		M=max(M,dis[i]);
	bool pt=false;
	for(int i=2;i<=n;++i)
		if(dis[i]==M)
		{
			++num;
			if(!pt)
			{
				pt=true;
				po=i;
			}
		}
	printf("%d %d %d",po,M,num);
	return 0;
}
