#include<bits/stdc++.h>
using namespace std;
int sum[300005],a[300005];
int usd[300005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(usd,0,sizeof(usd));
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int tt;
			scanf("%d",&tt);
			int l=max(1,i-tt),r=min(n,i+tt);
			++sum[l];
			--sum[r+1];
		}
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			tot+=sum[i];
			++usd[tot];
		}
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		bool ky=true;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>n||!usd[a[i]])
			{
				ky=false;
				break;
			}
			else
				--usd[a[i]];
		}
		if(ky)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
