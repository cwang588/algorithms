#include<cstdio>
#include<queue>
#include<utility>
#define INF 0.0
using namespace std;
priority_queue<pair<double,int>,vector<pair<double,int> > > x;
double dis[100005];
bool used[100005];
int cnt;
struct edge
{
	int from,to,next;
	double value;
}e[500005];
int head[100005];
void add(int a,int b,double c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].value=c;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int main()
{
	int n,m,s;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,1.0-(double)c/100.0);
		add(b,a,1.0-(double)c/100.0);
	}
	int A,B;
	scanf("%d%d",&A,&B);
	for(int i=1;i<=n;++i)
		dis[i]=0.005;
	dis[A]=1.0;
	x.push(make_pair(1.0,A));
	while(!x.empty())
	{
		int now=x.top().second;
		x.pop();
		if(!used[now])
		{
			used[now]=true;
			for(int i=head[now];i;i=e[i].next)
			{
				if(dis[e[i].to]<dis[e[i].from]*e[i].value)
					dis[e[i].to]=dis[e[i].from]*e[i].value;
				x.push(make_pair(dis[e[i].to],e[i].to));
			}
		}
	}
	printf("%.8lf",100.0/dis[B]);
	return 0;
}
