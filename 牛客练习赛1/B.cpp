#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long jc[305],c[305][305];
void init()
{
	jc[1]=1;
	for(int i=0;i<=300;++i)c[i][0]=1;
	for(int i=2;i<=300;++i)jc[i]=(jc[i-1]*i)%mod;
	for(int i=1;i<=300;++i)
		for(int j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
}
int main()
{
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+(c[n-1][i-1]*jc[i]%mod)*c[m][i]%mod)%mod;		
	printf("%lld\n",ans);
	return 0;
}
