#include<cstdio>
#include<algorithm>
using namespace std;
int dis[105][105];
int cbt[10005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&cbt[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&dis[i][j]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int tot=0;
//	tot+=dis[1][cbt[1]];
	for(int i=2;i<=m;++i)
		tot+=dis[cbt[i-1]][cbt[i]];
//	tot+=dis[cbt[n]][n];
	printf("%d",tot); 
	return 0;
}
