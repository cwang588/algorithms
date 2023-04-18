#include<bits/stdc++.h>
using namespace std;
int x[55];
bool usd[40000006];
int n;
bool IIsPrime(int x)
{
	if(!x)
		return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
			return false;
	return true;
}
int tot,ans1=0,ans2=0;;
void dfs(int dpt)
{
	if(dpt==n+1)
	{
		if(IIsPrime(tot))
		{
			++ans1;
			if(!usd[tot])
				++ans2;
			usd[tot]=true;
		}
		return;
	}
	tot+=x[dpt];
	dfs(dpt+1);
	tot-=x[dpt];
	dfs(dpt+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	dfs(1);
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
