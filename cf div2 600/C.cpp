#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long sum[200005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)b[i%m]+=a[i];
	long long ans=0;
	for(int i=n;i>=1;--i)
	{
		int now=n-i+1;
		ans+=((now-1)/m+1)*a[i];
	}
	sum[n]=ans;
	for(int i=n-1;i>=1;--i)
	{
		ans-=b[(i+1)%m];
		b[(i+1)%m]-=a[i+1];
		sum[i]=ans;
	}
	for(int i=1;i<=n;++i)cout<<sum[i]<<' ';
	return 0;
} 
