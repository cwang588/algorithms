#include<bits/stdc++.h>
using namespace std;
int a[200005];
map<int,long long>m;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	long long ans=0;
	m[0]=1;
	for(int i=1;i<=n;++i)
	{
		a[i]^=a[i-1];
		ans+=m[a[i]];
		++m[a[i]];
	}
	printf("%lld\n",ans);
	return 0;
}
