#include<bits/stdc++.h>
using namespace std;
char a[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=n;
		for(int i=1;i<=n;++i)
		{
			if(a[i]=='1')
			{
				ans=max(ans,2*i);
				ans=max(ans,2*(n-i+1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
