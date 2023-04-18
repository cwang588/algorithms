#include<cstdio>
#define INF 2147483647
#include<queue>
#include<cstring>
using namespace std;
struct edge
{
	int from,to,v1,v2,next;
}e[200005];
int head[100005];
long long dis[100005];
int cnt;
void init()
{
	cnt=0;
	memset(head,0,sizeof(head));
	memset(dis,0,sizeof(head));
}
long long dfs1(int x)
{
	if(dis[x])
		return dis[x];
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			++cnt;
			int s;
			scanf("%d%d%d%d%d",&e[cnt].from,&e[cnt].to,&s,&e[cnt].v1,&e[cnt].v2);
			e[cnt].v1-=s;
			e[cnt].v2-=s;
			e[cnt].v1*=-1;
			e[cnt].v2*=-1;
			e[cnt].next=head[e[cnt].from];
			head[e[cnt].from]=cnt;
		}
		long long ans1=dfs1(n);
		if(ans2>ans1)
			printf("cnznb!!!\n%lld",ans2-ans1);
		else if(ans1>ans2)
			printf("rip!!!\n%lld",ans1-ans2);
		else
			printf("oof!!!");
	}
	return 0;
}
