#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;++i)
	{
		long long t;
		scanf("%lld",&t);
		int l=1,r=n+1;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			long long tt=a[m];
			if(tt==t)
			{
				printf("YES\n");
				goto yy;
			}
			if(tt<t)
				l=m;
			if(tt>t)
				r=m;
		}
		if(a[r]==t)
			printf("YES\n");
		else
			printf("NO\n");
		yy:continue;
	}
	return 0;
}
