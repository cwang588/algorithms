#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt,v;
}e[2000005];	
int cnt,Head[10005],t[10005];
const int INF=2147483647;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dis[100005];
bool used[100005];
void add(int a,int b,int c)
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
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int tt;
		scanf("%d",&tt);
		scanf("%d",&tt);
		t[i]=tt;
		scanf("%d",&tt);
		add(0,i,0);
		while(tt)
		{
			add(tt,i,-t[tt]);
			scanf("%d",&tt);
		}
		add(i,n+1,-t[i]);
	}
	for(int i=1;i<=n+1;++i)dis[i]=INF;
	q.push(make_pair(0,0));
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
	printf("%d\n",-dis[n+1]);
	return 0;
}
