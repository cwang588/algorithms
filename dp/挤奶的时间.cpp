#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
queue<int> q;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > qq;
struct edge
{
	int from,to,value,next;
}e[500005];
struct list
{
	int l,r,e;
}t[50005];
int head[10005],dis[10005];
int cnt;
bool usd[10005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	int N,M,R;
	scanf("%d%d%d",&N,&M,&R);
	for(int i=1;i<=M;++i)
		scanf("%d%d%d",&t[i].l,&t[i].r,&t[i].e);
	for(int i=1;i<=M;++i)
	{
		add(0,i,0);
		add(i,M+1,t[i].e*(-1));
	}
	for(int i=1;i<=M;++i)
		for(int j=1;j<=M;++j)
		{
			if(t[i].r+R<=t[j].l)
				add(i,j,t[i].e*(-1)); 
		}	
	int n=M,s=0;
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].next)
		{
			if(dis[e[i].to]>dis[e[i].from]+e[i].value)
			{
				dis[e[i].to]=dis[e[i].from]+e[i].value;
				if(!usd[e[i].to])
				{
					usd[e[i].to]=true;
					q.push(e[i].to);
				}
			}
		}
		usd[now]=false; 
	}
	printf("%d",dis[M+1]*(-1));
	return 0;
}
