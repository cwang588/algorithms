#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int tmp;
			scanf("%d",&tmp);
			++a[tmp];
		}
		int ans=0;
		for(int i=0;i<=200;++i)
		{
			if(!a[i])
			{
				ans+=i;
				break;
			}
			else --a[i];
		}
		for(int i=0;i<=200;++i)
		{
			if(!a[i])
			{
				ans+=i;
				break;
			}
			else --a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
