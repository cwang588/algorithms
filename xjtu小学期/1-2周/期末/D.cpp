#include<bits/stdc++.h>
using namespace std;
bool usd[200005];
queue<pair<int,int> >q;
struct edge
{
	int from,to,next;
}e[400005];
int head[200005];
int cnt;
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
int main()
{
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	q.push(make_pair(a,0));
	usd[a]=true;
	while(!q.empty())
	{
		int now=q.front().first,nowtot=q.front().second;
		q.pop();
		if(now==b)
			return !printf("%d",nowtot+1);
		for(int i=head[now];i;i=e[i].next)
		{
			if(!usd[e[i].to])
			{
				q.push(make_pair(e[i].to,nowtot+1));
				usd[e[i].to]=true;
			}
		}
	}
	printf("-1");
	return 0;
}
