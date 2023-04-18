#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[100005];
int Head[50005],cnt;
bool usd[50005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	bool ky=true;
	int cnt=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		++cnt;
		dfs(to,now);
		if(!usd[to])ky=!ky;
	}
	if(cnt==1)ky=!ky;
	usd[now]=ky;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		if(usd[1])printf("Alice\n");
		else printf("Bob\n");
		for(int i=1;i<=n;++i)Head[i]=0;
		cnt=0;
	}
	return 0;
} 
