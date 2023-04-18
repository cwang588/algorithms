#include<cstdio>
#include<algorithm>
#define INF 1000000
using namespace std;
int dis[105][105];
bool brea[105][105];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=(i!=j)?INF:0;
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=dis[b][a]=c;
	}
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		brea[a][b]=brea[b][a]=true;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(dis[i][j]!=INF&&!brea[i][j])
				dis[i][j]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int A,B;
	scanf("%d%d",&A,&B);
	printf("%d",dis[A][B]);
	return 0;
}
