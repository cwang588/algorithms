#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
int dis[200005],ans[200005],tep[200005];
bool used[200005],usd[200005];
int n;
long long tot=1;
int cnt,cntt;
struct edge
{
	int from,to,v,next,id;
}e[500005],ee[500005];
int head[200005],headd[200005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int father[200005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void unionn(int a,int b)
{
    father[b]=a;
}
bool cmp(edge a,edge b)
{
	return a.id<b.id;
}
void addd(int x,int y,int z)
{
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].id=z/2;
	ee[cntt].next=headd[x];
	headd[x]=cntt;	
}
int main()
{
	int m;
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	for(int i=1;i<=n;++i)
		dis[i]=(i==1)?0:INF;
	x.push(make_pair(0,1));
	ans[1]=1;
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
				{
					dis[e[i].to]=dis[e[i].from]+e[i].v;
					ans[e[i].to]=ans[e[i].from];
				}
				else if(dis[e[i].to]==dis[e[i].from]+e[i].v)
					ans[e[i].to]=ans[e[i].from]+1;
				x.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		tot*=ans[i];
		if(tot>=k)
		{
			tot=k;
			break;
		}
	}
	printf("%lld\n",tot);
	for(int i=1;2*i<=cnt;++i)
		if(dis[e[i].to]==dis[e[i].from]+e[i].v||dis[e[i].from]==dis[e[i].to]+e[i].v)
			addd(e[i].from,e[i].to,i);
	sort(ee+1,ee+1+cntt,cmp);
	for(int i=1;i<=cntt;++i)
	{

	}
	return 0;
}
