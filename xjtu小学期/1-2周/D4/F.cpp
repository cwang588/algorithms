#include<bits/stdc++.h>
using namespace std;
int tong[35],ans[105];
int n;
void dfs(int tot,int now)
{
	if(now==n+1)
	{
		for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		exit(0);
	}
	for(int i=1;i<=30;++i)
		if(tong[i]&&tot%i==0)
		{
			--tong[i];
			ans[now]=i;
			dfs(tot+i,now+1);
			++tong[i];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		++tong[t]; 
	}
	dfs(0,1);
	printf("-1");
	return 0;
} 
