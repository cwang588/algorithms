#include<bits/stdc++.h>
const long long INF=1000000000000000000;
using namespace std;
struct edge
{
	int from,to,nxt;
	long long v;
}e[1000005];
bool usd[1000005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int Head[1000005],cnt;
long long dis[1000005];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		for(int j=0;j<=k;++j)
		{
			add(x+j*n,y+j*n,z);
			if(j!=k)
				add(x+j*n,y+(j+1)*n,z/2);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<k;++j)
			add(j*n+i,(j+1)*n+i,0);	
	for(int i=1;i<=n*k+n;++i)
		dis[i]=(i==1)?0:INF;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
					dis[e[i].to]=dis[e[i].from]+e[i].v;
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	if(dis[n*k+n]==INF)printf("-1\n");
	else printf("%lld\n",dis[n*k+n]);
	return 0;
}
