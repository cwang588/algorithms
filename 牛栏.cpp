#include<cstdio>
#include<algorithm>
#define INF 1000001
using namespace std;
int dis[305][305];
int s[40005],e[40005];
int main()
{
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=INF;
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=c;
	}
	for(int i=1;i<=t;++i)
		scanf("%d%d",&s[i],&e[i]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
	for(int i=1;i<=t;++i)
		printf("%d\n",(dis[s[i]][e[i]]>=INF)?(-1):dis[s[i]][e[i]]);
}
