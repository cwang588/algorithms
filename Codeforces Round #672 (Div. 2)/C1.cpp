#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		long long ans=0;
		if(n==1)ans=a[1];
		else
		{
			int cnt=0;
			if(a[1]>a[2])++cnt,ans+=a[1];
			long long last;
			for(int i=2;i<n;++i)
			{
				if(a[i]>a[i-1]&&a[i]>a[i+1])++cnt,ans+=a[i];
				if(a[i]<a[i-1]&&a[i]<a[i+1])
				{
					ans-=a[i];
					++cnt;
					last=a[i];
				}
			}
			if(a[n]>a[n-1])ans+=a[n],++cnt;
			if(a[n]<a[n-1])ans-=a[n],++cnt,last=a[n];
			if(cnt%2==0)ans+=last;
		}
		printf("%lld\n",ans);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
		}
	}
	return 0;
}
