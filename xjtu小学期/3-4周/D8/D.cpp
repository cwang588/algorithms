#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > x;
int dis1[200005],dis2[200008];
bool used1[200005],used2[200008];
int cnt1,cnt2;
struct edge
{
	int from,to,v,next;
}e1[1000005],e2[1000005];
int head1[200005],head2[200005];
void add1(int x,int y,int z)
{
	++cnt1;
	e1[cnt1].from=x;
	e1[cnt1].to=y;
	e1[cnt1].v=z;
	e1[cnt1].next=head1[x];
	head1[x]=cnt1;
}
void add2(int x,int y,int z)
{
	++cnt2;
	e2[cnt2].from=x;
	e2[cnt2].to=y;
	e2[cnt2].v=z;
	e2[cnt2].next=head2[x];
	head2[x]=cnt2;
}
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add1(x,y,z);
		add2(y,x,z);
	}
	for(int i=1;i<=n;++i)
		dis2[i]=dis1[i]=(i==p)?0:INF;
	x.push(make_pair(0,p));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used1[now])
		{
			used1[now]=true;
			for(int i=head1[now];i;i=e1[i].next)
			{
				if(dis1[e1[i].to]>dis1[e1[i].from]+e1[i].v)
					dis1[e1[i].to]=dis1[e1[i].from]+e1[i].v;
				x.push(make_pair(dis1[e1[i].to],e1[i].to));
			}
		}
	}
	x.push(make_pair(0,p));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used2[now])
		{
			used2[now]=true;
			for(int i=head2[now];i;i=e2[i].next)
			{
				if(dis2[e2[i].to]>dis2[e2[i].from]+e2[i].v)
					dis2[e2[i].to]=dis2[e2[i].from]+e2[i].v;
				x.push(make_pair(dis2[e2[i].to],e2[i].to));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,dis1[i]+dis2[i]);
	printf("%d",ans);
	return 0;
}
