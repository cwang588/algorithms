#include<cstdio>
#include<queue>
#include<iostream>
#include<utility>
#define INF 9223372036854775807
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
long long dis[2000005];
bool used[2000005],train[2000005];
int cnt;
struct edge
{
	int from,to,nxt;
	long long v;
}e[6000005];
int Head[2000005];
void add(int xx,int yy,long long zz)
{
	++cnt;
	e[cnt].from=xx;
	e[cnt].to=yy;
	e[cnt].v=zz;
	e[cnt].nxt=Head[xx];
	Head[xx]=cnt;
}
int ans;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int xx,yy,zz;
		cin>>xx>>yy>>zz;
		add(xx,yy,zz);
		add(yy,xx,zz);
	}
	for(int i=1;i<=n;++i)
		dis[i]=(i==1)?0:INF;
	for(int i=1;i<=k;++i)
	{
		int t;
		long long num;
		cin>>t>>num;
		if(dis[t]!=INF)
			++ans;
		dis[t]=min(dis[t],num);
		train[t]=true;
	}
	x.push(make_pair(0,1));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].v;
					if(train[e[i].to])
					{
						train[e[i].to]=false;
						++ans;
					}
				}
				else if(dis[e[i].to]==dis[e[i].from]+e[i].v)
				{
					if(train[e[i].to])
					{
						train[e[i].to]=false;
						++ans;
					}					
				}
				x.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	printf("%d",ans);
	return 0;
}
