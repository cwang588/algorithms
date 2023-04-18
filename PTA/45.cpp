#include<cstdio>
#include<cstring>
using namespace std;
struct edge
{
	int from,to,next;
}e[500005];
bool usd[505],col[505];
int head[505],cnt;
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
void dfs(int now)
{
	col[now]=true;
	for(int i=head[now];i;i=e[i].next)
		if(!col[e[i].to]&&!usd[e[i].to])
			dfs(e[i].to);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	int k,num=n,Max=0;
	for(int j=0;j<n;++j)
	if(!usd[j]&&!col[j])
	{
		dfs(j);
		++Max;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;++i)
	{
		memset(col,false,sizeof(col));
		int t,sum=0;
		scanf("%d",&t);
		usd[t]=true;
		--num;
		if(!num)
			return !printf("City %d is lost.\nGame Over.\n",t);
		for(int j=0;j<n;++j)
			if(!usd[j]&&!col[j])
			{
				dfs(j);
				++sum;
			}
		if(sum>Max)
			printf("Red Alert: City %d is lost!\n",t);
		else
			printf("City %d is lost.\n",t);
		Max=sum;
	}
	return 0;
}
