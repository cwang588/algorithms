#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dis[105][105];
int f[(1<<10)][105];
int bz[15]; 
int main()
{
	int n,p;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&dis[i][j]);
	scanf("%d",&p);
	for(int i=1;i<=p;++i)
		scanf("%d",&bz[i]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	memset(f,0x7f,sizeof(f));
	int M=(1<<p)-1;
	for(int i=1;i<=p;++i)
		f[1<<i-1][bz[i]]=dis[1][bz[i]];
	for(int i=1;i<=M;++i)
		for(int j=1;j<=p;++j)
			if(i&(1<<j-1))
				for(int k=1;k<=p;++k)
					if(!(i&1<<k-1))
						f[i|(1<<k-1)][bz[k]]=min(f[i|(1<<k-1)][bz[k]],f[i][bz[j]]+dis[bz[j]][bz[k]]);
	int Min=2147483647;
	for(int i=1;i<=p;++i)
		Min=min(Min,f[M][bz[i]]+dis[bz[i]][n]);
	printf("%d",Min);
	return 0;
}
