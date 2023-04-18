#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int head[50005];
int dis[50005];
bool usd[50005];
int cnt;
struct edge
{
	int to,from,value,next;
}e[500005];
int p[100005],qq[100005];
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
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{ 
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=s;++i)
		scanf("%d%d",&p[i],&qq[i]);
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
	for(int i=1;i<=s;++i)
		printf("%d\n",dis[p[i]]+dis[qq[i]]);
	return 0;
}
