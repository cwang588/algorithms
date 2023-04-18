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
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%I64d",&a[i]);
			if(a[i]>0)++cnt;
		}
		sort(a+1,a+1+n);
		if(!cnt)
		{
			printf("%I64d\n",a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
			continue;
		}
		long long ans=-1145141919810114;
		ans=max(ans,a[n]*a[1]*a[2]*a[3]*a[4]);
		if(cnt>=3)ans=max(ans,a[n]*a[n-1]*a[n-2]*a[1]*a[2]);
		if(cnt>=5)ans=max(ans,a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
		printf("%I64d\n",ans);
	}
	return 0;
}
