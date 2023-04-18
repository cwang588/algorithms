#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
int dis[100005];
bool used[100005];
int cnt;
struct edge
{
	int from,to,v,next;
}e[500005];
int head[100005];
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].v=c;
	e[cnt].next=head[a];
	head[a]=cnt;
}
int main()
{
	int a,b,xx,y;
	scanf("%d%d%d%d",&a,&b,&xx,&y);
	for(int i=1;i<=100;++i)
		for(int j=1;j<=100;++j)
			add(i,j,abs(i-j));
	add(xx,y,0);
	add(y,xx,0);
	for(int i=1;i<=100;++i)
		dis[i]=(i==a)?0:INF;
	x.push(make_pair(0,a));
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
	printf("%d ",dis[b]);
	return 0;
}
