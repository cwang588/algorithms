#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int last[5005],rd[5005],dp[5005][5005];
queue<int>q;
struct edge
{
	int from,to,v,nxt;
}e[10005];
bool usd[10005],hf[10005];
int cnt,Head[10005];
void dfs(int now)
{
	hf[now]=true;
	for(int i=Head[now];i;i=e[i].nxt)
		if(!hf[e[i].to])
			dfs(e[i].to);		
}
int main()
{
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;++i)
	{
		++cnt;
		scanf("%d%d%d",&e[cnt].from,&e[cnt].to,&e[cnt].v);
		e[cnt].nxt=Head[cnt];
		Head[cnt]=e[cnt].from;
		++rd[y];
	}
	dfs(1);
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=)
	}
	return 0;
}
