#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		k%=2;
		int Max=-2147483647,Min=2147483647;
		for(int i=1;i<=n;++i)Max=max(Max,a[i]),Min=min(Min,a[i]);
		if(k)
		{
			for(int i=1;i<=n;++i)printf("%d ",Max-a[i]);
			printf("\n");
		}
		else 
		{
			for(int i=1;i<=n;++i)printf("%d ",a[i]-Min);
			printf("\n");
		}
	}
	return 0;
}
