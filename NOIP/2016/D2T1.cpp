#include<bits/stdc++.h>
using namespace std;
int c[2005][2005],sum[2005][2005],k;
void init()
{
	for(int i=0;i<=2000;++i)
		for(int j=0;j<=2000;++j)
			c[i][j]=1;
	for(int i=1;i<=2000;++i)
		for(int j=1;j<i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
	for(int i=1;i<=2000;++i)
		for(int j=1;j<=2000;++j)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(!c[i][j])
				++sum[i][j];
		}
}
int main()
{
	int t;
	scanf("%d%d",&t,&k);
	init();
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",sum[n][m]);
	}
	return 0;
}
