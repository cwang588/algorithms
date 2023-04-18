#include<bits/stdc++.h>
using namespace std;
queue<int> q;
const long long INF=92233720368547758;
struct edge
{
	int from,to,nxt;
	long long value;
}e[5005];
int Head[305];
long long dis[305];
int cnt;
bool usd[105];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		memset(Head,0,sizeof(Head));
		memset(dis,0,sizeof(dis));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			long long z;
			cin>>x>>y>>z;
			++x;
			++y;
			add(x,y,z);
		}
		for(int now=1;now<=6;++now)
		{
			memset(usd,false,sizeof(usd));
			int x,y;
			scanf("%d%d",&x,&y);
			++x;
			++y;
			for(int i=1;i<=n;++i)
				dis[i]=INF;
			dis[y]=0;
			q.push(y);
			while(!q.empty())
			{
				int now=q.front();
				q.pop();
				for(int i=Head[now];i;i=e[i].nxt)
				{
					if(dis[e[i].to]>dis[e[i].from]+e[i].value)
					{
						dis[e[i].to]=dis[e[i].from]+e[i].value;
						if(!usd[e[i].to])
						{
							usd[e[i].to]=true;
							q.push(e[i].to);
						}
					}
				}
				usd[now]=false; 
			}
			printf("%lld\n",-dis[x]);
			add(x,y,-dis[x]);
		}
	}
	return 0;
}
