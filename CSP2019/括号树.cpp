#include<bits/stdc++.h>
using namespace std;
set<int>ss;
struct edge
{
	int from,to,nxt;
}e[1000005];
int Head[500005],cnt;
char s[500005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int tot,fstot;
long long ans,nowans,tong[500005];
void dfs(int now,int pre)
{
	if(s[now]=='(')++tot;
	else
	{
		--tot;
		if(tot<0)
		{
			++fstot;
			
		}
		ans+=tong[tot];
		++tong[tot];
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
	}
	--tong[tot];
	if(s[now]=='(')--tot;
	else ++tot;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=2;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		add(i,t);
		add(t,i);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
