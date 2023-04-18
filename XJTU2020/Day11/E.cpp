#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x+y-z==0)printf("2000000000\n");
		else
		{
			if(x+y-z>max(x,z))printf("%d\n",x+y-z);
			else printf("-1\n");
		}
	}
	return 0;
} 
