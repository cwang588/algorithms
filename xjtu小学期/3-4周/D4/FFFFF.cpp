#include<bits/stdc++.h>
using namespace std;
int tong[35],ans[105];
int n;
int db[3005][35]={{30,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}};
void dfs(int now,int tot)
{
	if(now==0)
	{
		for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		exit(0);
	}
	for(int i=1;i<=db[tot][0];++i)
		if(tong[db[tot][i]])
		{
			--tong[db[tot][i]];
			ans[now]=db[tot][i];
			dfs(now-1,tot-db[tot][i]);
			++tong[db[tot][i]];
		}
}
int main()
{
	int ttot=0;
	scanf("%d",&n);
	for(int i=1;i<=3000;++i)
	{
		int num=0;
		for(int j=1;j<=min(i,30);++j)
			if(i%j==0)
				db[i][++num]=j;
		db[i][0]=num;
	}
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		++tong[t];
		ttot+=t;
	}	
	dfs(n,ttot);
	printf("-1");
	return 0;
}
