#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> > >q;
struct edge
{
	int from,to,value,next;
}e[100005],shu[20005];
struct yun
{
	int x,y;
}h[30005];
int head[10005],fa[10005],headd[10005],depth[10005],usd[10005];
int cnt,cntt;
int ff(int x)
{
	if(fa[x])
		return fa[x];
	return fa[x]=ff(fa[x]);
}
void uu(int a,int b)
{
	fa[b]=a;	
}
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
	q.push(make_pair(e[cnt].value,cnt));
}
void addd(int x,int y,int z)
{
	++cntt;
	shu[cnt].from=x;
	shu[cnt].to=y;
	shu[cnt].value=z;
	shu[cnt].next=headd[shu[cnt].from];
	headd[shu[cnt].from]=cntt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int r1=ff(a),r2=ff(b);
		if(r1!=r2)
			uu(a,b);
		add(a,b,c);
		add(b,a,c);
	}
	int sum=1;
	while(sum<n)
	{
		int now=q.top().second;
		if(ff(e[now].from)!=ff(e[now].to))
		{
			++sum;
			uu(e[now].from,e[now].to);
			addd(e[now].from,e[now].to,e[now].value);
			addd(e[now].to,e[now].from,e[now].value);
			q.pop();
		}
		else
			q.pop();
	}
	for(int i=1;i<=q;++i)
		scanf("%d%d",&h[i].x,&h[i].y);
	for(int i=1;i<=n;++i)
		if(!usd[i])
			dfs(i);
	return 0;
}
