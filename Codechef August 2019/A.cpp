#include<bits/stdc++.h>
using namespace std;
int a[155],b[155];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);	
		for(int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		int Max=0;
		for(int i=1;i<=n;++i)
			Max=max(Max,a[i]*20-b[i]*10);
		printf("%d\n",Max);
	}
	return 0;
}
