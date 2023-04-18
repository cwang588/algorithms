#include<bits/stdc++.h>
using namespace std;
int a[400005];
int main()
{
	int n;
	long long ans=0,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		tot+=(long long)a[i];
		if(a[i]%2)
		{
			if(i%2)ans+=(long long)(a[i]/2+1);
			else ans+=(long long)(a[i]/2);
		}
		else ans+=(long long)(a[i]/2);
	}
	ans=min(ans,tot-ans);
	cout<<ans<<endl;
	return 0;
}
