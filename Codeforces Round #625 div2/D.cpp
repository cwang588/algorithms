#include<bits/stdc++.h>
using namespace std;
queue<int>q;
struct edge
{
	int from,to,nxt;
}e[200005],ee[200005];
int Head[200005],cnt,Headd[200005],cntt;
int dis[200005],num[200005];
bool usd[200005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y)
{
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
int a[200005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x);
		addd(x,y);
	}
	for(int i=1;i<=n;++i)dis[i]=214748364;
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;++i)scanf("%d",&a[i]);
	dis[a[k]]=0;
	num[a[k]]=1;
	usd[a[k]]=true;
	q.push(a[k]);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
		//	if(to==a[k])continue;
			if(dis[to]>dis[now]+1)
			{
				dis[to]=dis[now]+1;
				num[to]=num[now];
				usd[to]=true;
				q.push(to);
			}
			else if(dis[to]==dis[now]+1)num[to]+=num[now];
			else;
		}
	}
	int Max=0,Min=0;
	for(int i=1;i<k;++i)
	{
		int numm=0,Mint=214748364;
		for(int j=Headd[a[i]];j;j=ee[j].nxt)
		{
			int to=ee[j].to;
			if(dis[to]<Mint)
			{
				Mint=dis[to];
				numm=1;
			}
			else if(dis[to]==Mint)++numm;
			else;
		}
		if(numm>1)++Max;
		else
		{
			if(dis[a[i+1]]!=Mint)++Max;
		}
		if(dis[a[i+1]]!=Mint)++Min;
	}
	printf("%d %d\n",Min,Max);
	return 0;
}
