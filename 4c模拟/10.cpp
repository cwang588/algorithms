#include<cstdio>
#include<algorithm> 
using namespace std;
struct yb
{
	int a,b;
	double dj;
}y[1005];
bool cmp(yb q,yb p)
{
	return q.dj>p.dj;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&y[i].a);
	for(int i=1;i<=n;++i)
		scanf("%d",&y[i].b);
	for(int i=1;i<=n;++i)
		y[i].dj=(double)y[i].b/(double)y[i].a;	
	sort(y+1,y+1+n,cmp);
	double tot=0.0;
	for(int i=1;i<=n;++i)
	{
		if(m<=y[i].a)
		{
			tot+=(double)m*y[i].dj;
			return !printf("%.2lf",tot);
		}
		else
		{
			tot+=(double)y[i].b;
			m-=y[i].a;
		}
	}
	printf("%.2lf",tot);
	return 0;
}
