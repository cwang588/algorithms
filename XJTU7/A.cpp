#include<cstdio>
#include<queue>
#include<utility>
#include<iostream>
#include<cstring>
using namespace std;
const int INF=2147483647;
queue<pair<int,int> >q;
int dis[100005];
bool usd[100005];
int cnt;
struct edge
{
	int from,to,v,nxt;
}e[500005];
int Head[100005];
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].v=c;
	e[cnt].nxt=Head[a];
	Head[a]=cnt;
}
void dfs(int now,int col,int d)
{
	usd[now]=true;
	q.push(make_pair(now,d));
	for(int i=Head[now];i;i=e[i].nxt)
		if(!usd[e[i].to]&&e[i].v==col)
			dfs(e[i].to,col,d);
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		cnt=0;
		memset(Head,0,sizeof(Head));
		memset(usd,false,sizeof(usd));
		for(int i=2;i<=n;++i)
			dis[i]=2147483647;
		for(int i=1;i<=m;++i) 
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		q.push(make_pair(1,0));
		usd[1]=true;
		while(!q.empty())
		{
			pair<int,int> t=q.front();
			q.pop();
			dis[t.first]=t.second;
			for(int i=Head[t.first];i;i=e[i].nxt)
			{
				if(!usd[e[i].to])	
					dfs(e[i].to,e[i].v,t.second+1);
			}
		}
		while(!q.empty())
			q.pop();
		if(dis[n]!=2147483647)
			printf("%d\n",dis[n]);
		else
			printf("-1\n");
	}
	return 0;
}
