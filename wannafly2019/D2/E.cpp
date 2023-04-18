#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
int a[105][15];
int main()
{
	freopen("cifrul.in","r",stdin);
	freopen("cifrul.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,d,k;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>a[i][j];
		long long ans=1;
		for(int i=1;i<=n;++i)
			sort(a[i]+1,a[i]+1+m);
		for(int i=1;i<=n;++i)
		{
			int now=m;
			a[i][m+1]=a[i][1]+k;
			for(int j=2;j<=m+1;++j)
				now+=min(2*d,a[i][j]-a[i][j-1]-1);
			ans=ans*(long long)now%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
