#include<bits/stdc++.h>
using namespace std;
int to[1000005];
int zhan[1000005],tail,sum[1000005],ans[1000005];
bool huan[1000005],usd[1000005];
void dfs(int now)
{
	usd[now]=true;
	zhan[++tail]=now;
	sum[now]=tail;
	if(ans[to[now]])
	{
		ans[now]=ans[to[now]]+1;
		return;
	}
	if(usd[to[now]])
	{
		ans[now]=sum[now]-sum[to[now]]+1;
		while(zhan[tail]!=to[now])
		{
			--tail;
			huan[zhan[tail]]=true;
		}
		return;
	}
	dfs(to[now]);
	if(!huan[now])ans[now]=ans[to[now]]+1;
	else ans[now]=ans[to[now]];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&to[i]);
	for(int i=1;i<=n;++i)if(!ans[i])dfs(i);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
} 
