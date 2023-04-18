#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		long long ans=0;
		for(int i=1;i<n;++i)
			if(a[i]>a[i+1])
				ans+=a[i]-a[i+1];
		printf("%lld\n",ans);
	}
	return 0;
}
