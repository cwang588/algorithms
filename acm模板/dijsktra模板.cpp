//dijsktra
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
const long long INF=1000000000000000;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
long long dis[100005];
bool used[100005];
int cnt;
struct edge
{
	int from,to,nxt;
	long long v;
}e[500005];
int Head[100005];
void add(int a,int b,long long c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].v=c;
	e[cnt].nxt=Head[a];
	Head[a]=cnt;
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		add(a,b,c);
	//	add(b,a,c);
	}
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].v;
					q.push(make_pair(dis[e[i].to],e[i].to));
				}
			}
		}	
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",dis[i]);	
	return 0;
}
