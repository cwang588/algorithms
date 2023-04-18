#include<bits/stdc++.h>
using namespace std;
int n;
int ans[15];
bool qp[15][15];
bool p[55],q[55],c[15];
int cnt;
void dfs(int dpt)
{
	if(dpt==n+1)
	{
		++cnt;
		if(cnt<=3)
		{
			for(int i=1;i<=n;++i)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!c[i]&&!p[n+i-dpt]&&!q[i+dpt])
		{
			ans[dpt]=i;
			c[i]=p[n+i-dpt]=q[i+dpt]=true;
			dfs(dpt+1);
			c[i]=p[n+i-dpt]=q[i+dpt]=false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);		
	printf("%d\n",cnt);
	return 0;
}
