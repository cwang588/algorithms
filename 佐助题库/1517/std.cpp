#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>usd;
int main()
{
//	freopen("zz15171.in","r",stdin);
//	freopen("zz15171.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(usd[x])continue;
		usd[x]=i;
	}
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		printf("%d ",usd[x]?usd[x]:-1);
	}
	return 0;
} 
