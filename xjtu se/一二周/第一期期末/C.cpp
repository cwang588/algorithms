#include<bits/stdc++.h>
using namespace std;
bool usd[100005];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	usd[0]=true;
	for(int i=1;i<=n;++i)
	{
		if(i>=a)usd[i]|=usd[i-a];
		if(i>=b)usd[i]|=usd[i-b];
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans+=(usd[i]?0:1);
	printf("%d\n",ans);
	return 0;
}
