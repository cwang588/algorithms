#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		int x,y,k,tot=0,now=0;
		scanf("%d%d%d",&x,&y,&k);
		if(x>y)
		{
			printf("Case #%d: %d\n",i,k);
			continue;
		}
		for(int j=1;j<=k;++j)
		{
			if(now<11*y-9*x)
				now+=11*x;
			else
			{
				now-=(11*y-9*x);
				++tot;
			}
		}
		printf("Case #%d: %d\n",i,tot);
	}
	return 0;
} 
