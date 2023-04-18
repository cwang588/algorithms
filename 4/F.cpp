#include<cstdio>
#include<queue> 
using namespace std;
queue<int>q;
struct edge
{
	int from,to,value,next;
}e[200005];
int head[100005];
int cnt;
bool usd[100005];
int rd[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		++cnt;
		scanf("%d%d",&e[cnt].to,&e[cnt].from);
		++rd[e[cnt].to];
		e[cnt].next=head[e[cnt].from];
		head[e[cnt].from]=cnt;
	}
	for(int i=1;i<=n;++i)
		if(!rd[i])
			q.push(i);
	int wg=m+1;
	if(q.empty())
	{
		for(int i=m;i>=1;--i)
		{
			--rd[e[i].to];
			if(!rd[e[i].to])
		}
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].next)
			if(!usd[i])
			{
				--rd[e[i].to];
				if(!rd[e[i].to])
					q.push(e[i].to);
				usd[i]=true;
			}
	}
	for(int i=m;i>=1;--i)
		if(!usd[i])
		{
			wg=i;
			break;
		}
	for(int i=1;i<wg;++i)
		printf("YES\n");
	for(int i=wg;i<=m;++i)
		printf("NO\n");
	return 0;
}
