#include<bits/stdc++.h>
using namespace std;
int a[1005];
int tot1,tot2=1,tot=0;
void dfs(int now,int t)
{
	if(now==t+1)
	{
		if(tot1==tot2)
		{
			for(int i=1;i<=t;++i)
				printf("%d ",a[i]);
			printf("\n");
			++tot;
		}
		return;
	}
	for(int i=1;i<=10;++i)
	{
		a[now]=i;
		tot1+=i;
		tot2*=i;
		dfs(now+1,t);
		tot1-=i;
		tot2/=i;
	}
}
void solve(int n)
{
	dfs(1,n);
	printf("%d\n",tot);
	tot=0;
}
int main()
{
	for(int i=2;i<=8;++i)
	{
		solve(i);
	}
	
	return 0;
}
