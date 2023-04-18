#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int r[1005],c[1005],a[1005][1005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>r[i];
	for(int i=1;i<=m;++i)cin>>c[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=r[i];++j)a[i][j]=2;
		a[i][r[i]+1]=1;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=c[i];++j)
		{
			if(a[j][i]==1)return !printf("0\n");
			a[j][i]=2;
		}
		if(a[c[i]+1][i]==2)return !printf("0\n");
		a[c[i]+1][i]=1;
	}
	long long ans=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!a[i][j])
				ans=ans*2%mod;
	cout<<ans<<endl;
	return 0;
}
