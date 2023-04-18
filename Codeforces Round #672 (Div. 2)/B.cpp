#include<bits/stdc++.h>
using namespace std;
int a[35],mi[35];
void init()
{
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]*2;
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			for(int j=0;j<=29;++j)if(x>=mi[j]&&x<mi[j+1])++a[j];
		}
		long long ans=0;
		for(int j=0;j<=29;++j)ans+=(long long)a[j]*(long long)(a[j]-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
