#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,v,nxt;
}e[200005];
int cnt;
int Head[100005],num[100005];
bool usd[100005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int tot,int ccnt)
{
	usd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to])
		{
			if(to==1&&ccnt!=1)
			{
				if(ccnt%2)tot-=e[i].v;
				else tot+=e[i].v;
				num[1]=tot/2;
			}
			else continue;
		}
		if(ccnt%2)tot-=e[i].v;
		else tot+=e[i].v;
		dfs(to,tot,ccnt+1);
	}
}
void dfss(int now)
{
	usd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(usd[to])continue;
		num[to]=e[i].v-num[now];
		dfss(to);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;++i)usd[i]=false;
	dfss(1);
	for(int i=1;i<=n;++i)printf("%d\n",num[i]);
	return 0;
}
