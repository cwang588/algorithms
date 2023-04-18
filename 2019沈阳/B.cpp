#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[400005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int num[100005],numnow;
bool mon[100005],usd1[100005],usd2[100005],usd3[100005],f[100005];
struct monster
{
	int num1,num2,tot;
}mm[100005];
void dfs1(int now)
{
	usd1[now]=true;
	++numnow;
	for(int i=Head[now];i;i=e[i].nxt)
		if(!usd1[e[i].to]&&!mon[e[i].to])dfs1(e[i].to);
}
void dfs2(int now)
{
	usd2[now]=true;
	num[now]=numnow;
	for(int i=Head[now];i;i=e[i].nxt)
		if(!usd2[e[i].to]&&!mon[e[i].to])dfs2(e[i].to);
}
void dfs3(int now,int pre)
{
	usd3[now]=true;
	if(mon[now])
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			++mm[now].num2;
			if(!f[e[i].to])
			{
				mm[now].num1++;
				mm[now].tot+=num[e[i].to];
			}
		}
		return;
	}
	for(int i=Head[now];i;i=e[i].nxt)
		if(!usd3[e[i].to])dfs3(e[i].to,now);
}
bool uusd[100005];
void ddfs(int now)
{
	uusd[now]=true;
	f[now]=true;
	for(int i=Head[now];i;i=e[i].nxt)if(!uusd[e[i].to]&&!mon[e[i].to])ddfs(e[i].to);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		memset(mon,false,sizeof(mon));
		memset(usd1,false,sizeof(usd1));
		memset(usd2,false,sizeof(usd2));
		memset(usd3,false,sizeof(usd3));
		memset(uusd,false,sizeof(uusd));
		memset(f,false,sizeof(f));
		memset(num,0,sizeof(num));
		memset(Head,0,sizeof(Head));
		numnow=0;
		int n,m,k;	
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}	
		for(int i=1;i<=k;++i)
		{
			int t;
			scanf("%d",&t);
			mon[t]=true; 
		}
		for(int i=1;i<=n;++i)
		{
			if(!usd1[i]&&!mon[i])
			{
				numnow=0;
				dfs1(i);
				dfs2(i);
			}
		}
		ddfs(1);
		dfs3(1,0);
		double ans=num[1];
		for(int i=1;i<=n;++i)
		{
			if(mm[i].num1)
			{
				mm[i].tot+=num[1]*mm[i].num2;
				ans=max(ans,(double)mm[i].tot/(mm[i].num2));
			}
		}
		printf("%.8lf\n",ans);
		for(int i=1;i<=n;++i)
			mm[i].num1=mm[i].num2=mm[i].tot=0;
	}
	return 0;
}
