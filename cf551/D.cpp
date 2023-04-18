#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,next;
}e[600005];
int head[300005],f[300005],rd[300005];
int cnt,num,Min=999999;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int now,int pre,int tot)
{
	if(!rd[now])
	{
		Min=min(Min,tot);
		++num;
		return;
	}
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to!=pre)
		{
			if(!f[now])
				dfs(e[i].to,now,tot+rd[now]-1);
			else
				dfs(e[i].to,now,tot);	
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&f[i]);
	for(int i=2;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		++rd[x];
		add(i,x);
		add(x,i);
	}
	dfs(1,0,0);
	printf("%d",num-Min);
	return 0;
}
