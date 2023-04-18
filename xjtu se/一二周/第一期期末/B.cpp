#include<bits/stdc++.h>
using namespace std;
long long t[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&t[i]);
	sort(t+1,t+1+n);
	long long tot=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		tot+=t[i];
		ans+=tot;
	}
	printf("%lld\n",ans);
	return 0;
}
