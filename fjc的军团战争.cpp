#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long c[305][305],jc[304];
void init()
{
	jc[0]=1;
	for(int i=1;i<=300;++i)jc[i]=(jc[i-1]*i)%mod;
	for(int i=0;i<=300;++i)c[i][0]=1;
	for(int i=1;i<=300;++i)
		for(int j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
}
int main()
{
	int n,k; 
	scanf("%d%d",&n,&k);
	init();	
	long long ans=0;
	for(int i=1;i<=k;++i)
		ans=(ans+c[n-1][i-1]*jc[i]%mod*c[k][i]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
