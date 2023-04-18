#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
unsigned long long d[1000005];
unsigned long long ans[1000005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		++d[t];
	}
	for(int i=1;i<n;++i)
		ans[n]+=(n-i)*d[i];
	for(int i=1;i<=n;++i)
		d[i]+=d[i-1];
	for(int i=n-1;i>=1;--i)
		ans[i]=ans[i+1]-d[i]+d[n]-d[i];
	sort(ans+1,ans+1+n);
	unsigned long long num=0;
	for(int i=1;i<=k;++i)
		num+=ans[i];
	cout<<num; 
	return 0;
} 
