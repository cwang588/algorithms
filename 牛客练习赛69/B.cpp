#include<bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	int x,y;
	scanf("%d%d",&x,&y);
	long long ans=0;
	for(int i=1;i<=x;++i)
		for(int j=1;j<=y;++j)
			ans+=a[i*j];
	printf("%lld\n",ans);
	return 0;
}
