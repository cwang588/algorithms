#include<bits/stdc++.h>
using namespace std;
const long long INF=1919810114514;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
struct edge
{
	int from,to,nxt;
	long long value;
}e[2][200005];
int cnt,Head[2][100005];
long long dis[2][100005];
void add(int x,int y,long long z)
{
	++cnt;
	e[0][cnt].from=x;
	e[0][cnt].to=y;
	e[0][cnt].value=z;
	e[0][cnt].nxt=Head[0][x];
	Head[0][x]=cnt;
	e[1][cnt].from=y;
	e[1][cnt].to=x;
	e[1][cnt].value=z;
	e[1][cnt].nxt=Head[1][y];
	Head[1][y]=cnt;
}
bool usd[2][100005];
int n;
void dijsktra(int tmp)
{
	for(int i=1;i<=n;++i)dis[tmp][i]=INF;
	if(!tmp)dis[0][1]=0,q.push(make_pair(0,1));
	else dis[1][2]=0;q.push(make_pair(0,2));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[tmp][now])
		{
			usd[tmp][now]=true;
			for(int i=Head[tmp][now];i;i=e[tmp][i].nxt)
			{
				if(dis[tmp][e[tmp][i].to]>dis[tmp][e[tmp][i].from]+e[tmp][i].value)
				{
					dis[tmp][e[tmp][i].to]=dis[tmp][e[tmp][i].from]+e[tmp][i].value;
					q.push(make_pair(dis[tmp][e[tmp][i].to],e[tmp][i].to));
				}
			}
		}	
	}
	while(!q.empty())q.pop();
}
edge key[2][100005];
long long zxhnb[100005];
int Headd[2][100005],cntt;
int rd1[100005],rd2[100005];
void addd(int x,int y,long long z)
{
	++cntt;
	key[0][cntt].from=x;
	key[0][cntt].to=y;
	key[0][cntt].value=z;
	key[0][cntt].nxt=Headd[0][x];
	++rd1[y];
	Headd[0][x]=cntt;
	key[1][cntt].from=y;
	key[1][cntt].to=x;
	key[1][cntt].value=z;
	key[1][cntt].nxt=Headd[1][y];
	Headd[1][y]=cntt;
	++rd2[x];
}
long long num1[100005],num2[100005];
//void dfs1(int now,int pre)
//{
//	for(int i=Headd[0][now];i;i=key[0][i].nxt)
//	{
//		int to=key[0][i].to;
//		if(to==pre)continue;
//		num1[to]+=num1[now];
//		dfs1(to,now);
//	}
//}
//void dfs2(int now,int pre)
//{
//	for(int i=Headd[1][now];i;i=key[1][i].nxt)
//	{
//		int to=key[1][i].to;
//		if(to==pre)continue;
//		num2[to]+=num2[now];
//		dfs2(to,now);
//	}
//}
bool uusd1[100005],uusd2[100005];
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
	}
	dijsktra(0);
	dijsktra(1);
	for(int i=1;i<=m;++i)
	{
		int x=e[0][i].from,y=e[0][i].to;
		long long z=e[0][i].value;
		if(dis[0][x]+e[0][i].value+dis[1][y]==dis[0][2])
		{
			addd(x,y,z);
			zxhnb[i]=true;
		}
	}
	num1[1]=num2[2]=1;
	queue<int>q1,q2;
	q1.push(1);
	while(!q1.empty())
	{
		int now=q1.front();
		q1.pop();
		for(int i=Headd[0][now];i;i=key[0][i].nxt)
		{
			int to=key[0][i].to;
			num1[to]+=num1[now];
			--rd1[to];
			if(!rd1[to])q1.push(to);
		}
	}
	q2.push(2);
	while(!q2.empty())
	{
		int now=q2.front();
		q2.pop();
		for(int i=Headd[1][now];i;i=key[1][i].nxt)
		{
			int to=key[1][i].to;
			num2[to]+=num2[now];
			--rd2[to];
			if(!rd2[to])q2.push(to);
		}
	}
	for(int i=1;i<=m;++i)
	{
		int x=e[0][i].from,y=e[0][i].to;
		long long z=e[0][i].value;
		if(dis[0][y]+e[0][i].value+dis[1][x]<dis[0][2])printf("HAPPY\n");
		else
		{
			if(num1[x]*num2[y]==num1[2]&&zxhnb[i])printf("SAD\n");
			else printf("SOSO\n");
		}
	}
	return 0;
}
