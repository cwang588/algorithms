#include<bits/stdc++.h>
using namespace std;
long long sum[500005][15];
int n;
const long long mod=998244353;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int z)
{
	while(x<=n)
	{
		sum[x][y]=(sum[x][y]+z)%mod;
		x+=lowbit(x);
	}
}
long long query(int x,int y)
{
	long long re=0;
	while(x)
	{
		re=(re+sum[x][y])%mod;
		x-=lowbit(x);
	}
	return re;
}
int a[500005];
long long dp[500005][15];
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)
	{
		int now=getid(a[i]);
		dp[i][1]=1;
		add(now,1,1);
		for(int j=2;j<=k;++j)
		{
			dp[i][j]=(dp[i][k]+query(now-1,j-1))%mod;
			add(now,j,dp[i][j]);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;++i)ans=(ans+dp[i][k])%mod;
	printf("%lld\n",ans);
	return 0;
}
