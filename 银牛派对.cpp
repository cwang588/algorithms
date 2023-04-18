#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q1,q2;
int head1[10005],head2[10005];
int dis1[10005],dis2[10005];
bool usd1[10005],usd2[10005];
int cnt1,cnt2;
struct edge
{
	int to,from,value,next;
}e1[500005],e2[500005];
void add1(int a,int b,int c)
{
	++cnt1;
	e1[cnt1].from=a;
	e1[cnt1].to=b;
	e1[cnt1].value=c;
	e1[cnt1].next=head1[e1[cnt1].from];
	head1[e1[cnt1].from]=cnt1;
}
void add2(int a,int b,int c)
{
	++cnt2;
	e2[cnt2].from=a;
	e2[cnt2].to=b;
	e2[cnt2].value=c;
	e2[cnt2].next=head2[e2[cnt2].from];
	head2[e2[cnt2].from]=cnt2;
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add1(a,b,c);
		add2(b,a,c);
	}
	for(int i=1;i<=n;++i)
		dis1[i]=dis2[i]=INF;
	dis1[s]=dis2[s]=0;
	q1.push(make_pair(0,s));
	while(!q1.empty())
	{
		int now=q1.top().second;
		q1.pop();
		if(!usd1[now])
		{
			usd1[now]=true;
			for(int i=head1[now];i;i=e1[i].next)
			{
				if(dis1[e1[i].to]>dis1[e1[i].from]+e1[i].value)
					dis1[e1[i].to]=dis1[e1[i].from]+e1[i].value;
				q1.push(make_pair(dis1[e1[i].to],e1[i].to));
			}
		}
	}
	q2.push(make_pair(0,s));
	while(!q2.empty())
	{
		int now=q2.top().second;
		q2.pop();
		if(!usd2[now])
		{
			usd2[now]=true;
			for(int i=head2[now];i;i=e2[i].next)
			{
				if(dis2[e2[i].to]>dis2[e2[i].from]+e2[i].value)
					dis2[e2[i].to]=dis2[e2[i].from]+e2[i].value;
				q2.push(make_pair(dis2[e2[i].to],e2[i].to));
			}
		}
	}
	int M=-1;
	for(int i=1;i<=n;++i)
		M=max(M,dis1[i]+dis2[i]);
	printf("%d",M);
	return 0;
}
