#include<cstdio>
using namespace std;
int n,b;
struct edge
{
	int from,to,next;
}e[2005];
int cnt;
int head[1005];
void add(int u,int v)
{
	++cnt;
	e[cnt].from=u;
	e[cnt].to=v;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int k=0;
int sh[1005];
int sheng[1005];
int st=0;
int zhan[1005];
void dfs(int now,int pre)
{
	int t=st;
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to==pre)
			continue;
		dfs(e[i].to,now);
		if(st-t>=b)
		{
			sh[++k]=now;
			while(st>t)
				sheng[zhan[st--]]=k;
		}
	}
	zhan[++st]=now;
}
int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	if(!k)
		sh[++k]=1;
	while(st)
		sheng[zhan[st--]]=k;
	printf("%d\n",k);
	for(int i=1;i<=n;++i) 
		printf("%d ",sheng[i]);
	printf("\n");
    for(int i=1;i<=k;++i) 
		printf("%d ",sh[i]);
	return 0;
}
