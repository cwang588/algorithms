#include<cstdio>
using namespace std;
int a[1505][1505],b[1505][1550],c[1005][1505];
int main()
{
	int x,y,n,m;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=x;++i)
		for(int j=1;j<=y;++j)
			scanf("%d",&a[i][j]);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&b[i][j]);
	if(y!=n)
		return !printf("Error: %d != %d",y,n);
	for(int i=1;i<=x;++i)
		for(int j=1;j<=m;++j)
			for(int k=1;k<=y;++k)
				c[i][j]+=a[i][k]*b[k][j];
	printf("%d %d\n",x,m);
	for(int i=1;i<=x;++i)
		for(int j=1;j<=m;++j)
		{
			if(j!=m) 
				printf("%d ",c[i][j]);
			else
				printf("%d\n",c[i][j]);
		} 
	return 0;
}
