#include<bits/stdc++.h>
using namespace std;
int sum[2000006],num[2000006],a[2000006],now[2000006],nowans[2000006];
int main()
{
//	int t;
//	scanf("%d",&t);
//	while(t--)
//	{
		int n;
		scanf("%d",&n);
		long long ans=0;
		num[0]=1;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			a[i]^=a[i-1];
			if(!num[a[i]])
			{
				++num[a[i]];
				sum[a[i]]=i;
				now[a[i]]=i;
			}
			else
			{
				nowans[a[i]]+=(long long)(i-now[a[i]]-1)*(long long)num[a[i]];
				++num[a[i]];
				ans+=nowans[a[i]];
				now[a[i]]=i;
			}
		}
		printf("%lld",ans);
//	}
	return 0;
}
