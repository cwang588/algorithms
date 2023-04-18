#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge
{
	int from,to,next;
}e[400005];
int head[200005];
int cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int tot;
queue<int>q;
bool usd[200005];
priority_queue<int,vector<int>,greater<int> >qq;
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
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].next)
			if(!usd[e[i].to])
				qq.push(i);
		
	}
	return 0;
}
