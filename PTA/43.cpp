#include<cstdio>
using namespace std;
struct edge
{
	int from,to,next;
}e[200005];
int head[100005],fb[100005];
int cnt;
double r;
double gl[100005];
bool dd[100005];
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
void dfs(int now,int pre)
{
	if(!dd[now])
	{
		for(int i=head[now];i;i=e[i].next)
		{
			if(e[i].to!=pre)
			{
				gl[e[i].to]=gl[now]*(1.0-r/100.0);
				dfs(e[i].to,now);
			}
		}
	}
	else
		gl[now]*=(double)fb[now];
}
int main()
{
	int n;
	double z;
	scanf("%d%lf%lf",&n,&z,&r);
	gl[0]=z;
	for(int i=0;i<n;++i)
	{
		int t;
		scanf("%d",&t);
		if(!t)
		{
			dd[i]=true;
			scanf("%d",&fb[i]);
		}
		else
		{
			for(int j=1;j<=t;++j)
			{
				int x;
				scanf("%d",&x);
				add(i,x);
				add(x,i);
			}
		}
	}
	dfs(0,-1);
	double ans=0.0;
	for(int i=0;i<n;++i)
		if(dd[i])
			ans+=gl[i];
	printf("%d",(int)ans);
	return 0;
}
