#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long f[3505][3505];
int main()
{
	long long n,m;
	cin>>n>>m;
	f[1][1]=1;
	for(int i=2;i<=n;++i)
		for(int j=1;j<=i;++j)
			f[i][j]=(f[i-1][j-1]+(i-1)*f[i-1][j]%mod)%mod;
	cout<<f[n][m];
	return 0;
}
