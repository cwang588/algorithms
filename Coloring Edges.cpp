#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt,col;
}e[5005];
int cnt,Head[5005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
queue<int>q;
int rd[5005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		++rd[y];
		if(x>y)
			e[cnt].col=2;
		else
			e[cnt].col=1;
	}	
	int tot=0;
	for(int i=1;i<=n;++i)
		if(!rd[i])
		{
			q.push(i);
			++tot;
		}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=Head[now];i;i=e[i].nxt)
		{
			--rd[e[i].to];
			if(!rd[e[i].to])
			{
				q.push(e[i].to);
				++tot;				
			}
		} 
	}
	if(tot==n)
	{
		printf("1\n");
		for(int i=1;i<=m;++i)
			printf("1 ");
	}
	else
	{
		printf("2\n");
		for(int i=1;i<=m;++i)
			printf("%d ",e[i].col);
	}
	printf("\n");
	return 0;
}
