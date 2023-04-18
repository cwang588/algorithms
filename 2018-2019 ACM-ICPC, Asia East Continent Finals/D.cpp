#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int t;
		for(int i=1;i<=n+m;++i)cin>>t;
		if(n<=m)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
