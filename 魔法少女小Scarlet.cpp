#include<cstdio>
using namespace std;
int mo[1005][1005],tmp[1005][1005];
int main()
{
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			mo[i][j]=(i-1)*n+j;
	for(int i=1;i<=m;++i)
	{
		int x,y,r,z;
		scanf("%d%d%d%d",&x,&y,&r,&z);
		if(z)
		{
			for(int j=y+r;j>=y-r;--j)
				for(int k=x-r;k<=x+r;++k)
					tmp[j][k]=mo[k][2*y-j];
			for(int j=x-r;j<=x+r;++j)
				for(int k=y-r;k<=y+r;++k)
					mo[j][k]=tmp[j][k];
		}
		else
		{
			for(int j=y-r;j<=y+r;++j)
				for(int k=x+r;k>=x-r;--k)
					tmp[j][k]=mo[2*x-k][j];
			for(int j=x-r;j<=x+r;++j)
				for(int k=y-r;k<=y+r;++k)
					mo[j][k]=tmp[j][k];
		}
	}	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",mo[i][j]);
		printf("\n");
	}
	return 0;
 }
