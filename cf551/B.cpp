#include<cstdio>
using namespace std;
int f[105],l[105],H[105][105],t[105][105],cs[105][105][105];
int main()
{
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;++i)
		scanf("%d",&f[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&l[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&t[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=l[i];++j)
			for(int k=1;k<=m;++k)
				++cs[i][k][j];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=f[i];++j)
			for(int k=1;k<=n;++k)
				++cs[k][i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=1;k<=h;++k)
				if(t[i][j])
					++cs[i][j][k];
	for(int i=1;i<=n;++i)	
		for(int j=1;j<=m;++j)	
			for(int k=1;k<=h;++k)
				if(cs[i][j][k]==3)
					++H[i][j];
	for(int i=1;i<=n;++i)	
	{
		for(int j=1;j<=m;++j)
			printf("%d ",H[i][j]);	
		printf("\n");
	}
	return 0;
}
