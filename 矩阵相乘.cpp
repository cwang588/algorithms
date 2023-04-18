#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],b[10005][10005],c[10005][10005];
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=p;++j)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=p;++j)
			for(int k=1;k<=m;++k)
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=p;++j)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
} 
