/*–Ÿ—¿¿˚À„∑®*/ 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[100005];
int Head[1005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int vis[1005],mch[1005];
bool dfs(int now,int t)
{
	if(vis[now]==t)return false;
	vis[now]=t;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if((!mch[to])||dfs(mch[to],t))
		{
			mch[to]=now;
			return true;
		}
	}
	return false;
}
int main()
{
	int n,m,p; 
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y+n);
		add(y+n,x);
	}
	int ans=0;
	for(int i=1;i<=n;++i)if(dfs(i,i))++ans;
	printf("%d\n",ans);
	return 0;
}
