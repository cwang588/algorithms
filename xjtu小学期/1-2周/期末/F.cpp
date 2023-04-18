#include<bits/stdc++.h>
using namespace std;
int sum[150][150][150];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			for(int k=1;k<=c;++k)
			{
				int t;
				scanf("%d",&t);
				sum[i][j][k]=t+sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]-sum[i-1][j-1][k]-sum[i][j-1][k-1]-sum[i-1][j][k-1]+sum[i-1][j-1][k-1];
			}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int xx1,xx2,yy1,yy2,zz1,zz2;
		scanf("%d%d%d%d%d%d",&xx1,&yy1,&zz1,&xx2,&yy2,&zz2);
		printf("%d\n",sum[xx2][yy2][zz2]-sum[xx1-1][yy2][zz2]-sum[xx2][yy1-1][zz2]-sum[xx2][yy2][zz1-1]+sum[xx1-1][yy1-1][zz2]+sum[xx2][yy1-1][zz1-1]+sum[xx1-1][yy2][zz1-1]-sum[xx1-1][yy1-1][zz1-1]);
	}	
	return 0;
}
