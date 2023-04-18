#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=x;j<=y;++j)
			++a[j];
	}
	int ans=0;
	for(int i=1;i<=1000;++i)
		ans=max(ans,a[i]);
	printf("%d",ans);
	return 0;
}
