#include<bits/stdc++.h>
#define INF 9223372036854775807
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
long long dis[300005];
bool used[300005],usd[300005];
int bian[600005],father[300005];
int cnt;
int ans[300005];
struct edge
{
	int from,to,next,id;
	long long v;
}e[600005],E[600005];
int head[600005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void unionn(int a,int b)
{
    father[b]=a;
}
void add(int x,int y,long long z,int r)
{
	++cnt;
	e[cnt].id=r;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool cmp(edge a,edge b)
{
	if(a.v!=b.v)
		return a.v<b.v;
	return a.id<b.id;
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		add(a,b,c,i);
		add(b,a,c,i);
	}
	for(int i=1;i<=n;++i)
		dis[i]=(i==s)?0:INF;
	x.push(make_pair(0,s));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
					dis[e[i].to]=dis[e[i].from]+e[i].v;
				x.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	int nnum=0;
	for(int i=1;i<=m*2;++i)
		if(dis[e[i].to]==dis[e[i].from]+e[i].v)
		{
			bian[++nnum]=i;
			E[nnum].from=e[i].from;
			E[nnum].to=e[i].to;
			E[nnum].v=e[i].v;
			E[nnum].id=e[i].id;
		}
	for(int i=1;i<=n;++i)
		father[i]=i;
	sort(E+1,E+1+nnum,cmp);
	int num=0;
	long long tot=0;		
	for(int i=1;i<=nnum;++i)
	{
		int r1=find(E[i].from),r2=find(E[i].to);
		if(r1!=r2)
		{
			tot+=E[i].v;
			unionn(r1,r2);
			++num;	
			ans[num]=E[i].id;
		}
		if(num==n-1)
			break;
	}
	printf("%d %lld\n",num,tot);
	sort(ans+1,ans+1+num);
	for(int i=1;i<=num;++i)
		printf("%d ",ans[i]);
	return 0;
}
