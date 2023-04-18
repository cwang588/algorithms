#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,Nt;
}e1[100005],e2[100005];
int head1[100005],head2[100005];
int cnt1,cnt2;
void add(int x,int y)
{
	++cnt1;
	e1[cnt1].from=x;
	e1[cnt1].to=y;
	e1[cnt1].Nt=head1[x];
	head1[x]=cnt1;
	++cnt2;
	e2[cnt2].from=y;
	e2[cnt2].to=x;
	e2[cnt2].Nt=head2[y];
	head2[y]=cnt2;
}
bool usd[100005],vis[100005];
void dfs1(int now)
{
	for(int i=head1[now];i;i=e1[i].Nt)
	{
		if(!vis[e1[i].to])
		{
			usd[i]=true;
			vis[e1[i].to]=true;
			dfs1(e1[i].to);
		}
	}
}
void dfs2(int now)
{
	for(int i=head2[now];i;i=e2[i].Nt)
	{
		if(!vis[e2[i].to])
		{
			usd[i]=true;
			vis[e2[i].to]=true;
			dfs2(e2[i].to);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		memset(vis,false,sizeof(vis));
		vis[1]=true;
		dfs1(1);
		memset(vis,false,sizeof(vis));
		vis[1]=true;
		dfs2(1);	
		int re=m-2*n;
		for(int i=1;i<=m;++i)
		{
			if(!re)
				break;
			if(!usd[i])
			{
				printf("%d %d\n",e1[i].from,e1[i].to);
				--re;
			}
		}	
		cnt1=cnt2=0;
		memset(usd,false,sizeof(usd));
		memset(head1,0,sizeof(head1));
		memset(head2,0,sizeof(head2));
	}
	return 0;
}
