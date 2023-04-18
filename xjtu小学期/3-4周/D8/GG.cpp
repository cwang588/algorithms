#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,next;
}e[400005];
int head[200005];
int n,m,k,cnt;
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
vector<int>v[200005],bian[200005];
queue<pair<int,int> >q;
bool usd[200005],ans[400005];
int dis[200005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	usd[1]=true;
	v[1].push_back(1);
	q.push(make_pair(1,0));
	while(!q.empty())
	{
		int now=q.front().first,tot=q.front().second;
		q.pop();
		for(int i=head[now];i;i=e[i].next)
			if(!usd[e[i].to])
			{
				usd[e[i].to]=true;
				dis[e[i].to]=tot+1;
				q.push(make_pair(e[i].to,tot+1));
				v[tot+1].push_back(e[i].to);
			}
	}
	memset(usd,false,sizeof(usd));
	for(int i=1;i*2<=cnt;++i)
		if(dis[e[i].from]-dis[e[i].to]==1||dis[e[i].from]-dis[e[i].to]==-1)
			bian[max(dis[e[i].from],dis[e[i].to])].push_back(i/2);
	for(int i=1;i<=200000;++i)
		sort(bian[i].begin(),bian[i].end());
	dfs(0,)
	return 0;
}
