#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct edge
{
	int from,to;
	double value;
}e[1000005];
int cnt;
int fa[100005];
double x[100005],y[100005],z[100005],r[100005];
double getdis(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
bool cmp(edge a,edge b)
{
	return a.value<b.value;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		cnt=0;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=n;++i)scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				double dis=getdis(i,j);
				if(dis<=r[i]+r[j])Merge(i,j);
				else
				{
					++cnt;
					e[cnt].from=i;
					e[cnt].to=j;
					e[cnt].value=dis-r[i]-r[j];
				}
			}
		double ans=0.0;
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans+=e[i].value;
				Merge(e[i].from,e[i].to);
			}
		}
		printf("%.3f\n",ans);
		scanf("%d",&n);
	}	
	return 0;
}
