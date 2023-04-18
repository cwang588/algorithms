#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,next;
}e[400005];
int cnt;
int head[400005],rd[400005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool usd[200005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		++rd[y];
	}
	for(int i=1;i<=k;++i)
	{
		int t;
		scanf("%d",&t);
		if(!rd[t])
		{
			usd[t]=true;
			for(int j=head[t];j;j=e[j].next)
				--rd[e[j].to];
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(!usd[i])
			++ans;
	printf("%d",ans);
	return 0;
}
