#include<cstdio>
#include<iostream>
#define mod 19260817
using namespace std;
long long c[1005][1005],h[1005][1005];
void init()
{
	for(int i=1;i<=1000;++i)
		c[i][1]=i;
	for(int i=2;i<=1000;++i)
		for(int j=2;j<=i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	for(int i=1;i<=1000;++i)
		for(int j=1;j<=1000;++j)
			h[i][j]=(h[i-1][j]+h[i][j-1]-h[i-1][j-1]+c[i][j])%mod;
}
int main()
{
	int q;
	scanf("%d",&q);
	init();
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long ans=h[m][n];
		if(ans<0)
			ans+=mod;
		printf("%lld\n",ans);
	}
}
