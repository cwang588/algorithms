#include<bits/stdc++.h>
using namespace std;
long long c[50][50];
void init()
{
	for(int i=0;i<=20;++i)
		c[i][0]=1;
	for(int i=1;i<=20;++i)
		for(int j=1;j<=i;++j)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
}
long long ans[25][25];
int main()
{
	init();
	for(int n=2;n<=20;++n)
		for(int k=2;k<n;++k)
			for(int i=1;i<=ceil((double)n/k)-1;++i)
				ans[n][k]+=c[n-k*i+i][i];
	for(int i=1;i<=20;++i)
	{
		for(int j=1;j<=20;++j)
			printf("%lld ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
