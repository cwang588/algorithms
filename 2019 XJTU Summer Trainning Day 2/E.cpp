#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int tt; 
	scanf("%d",&tt);
	for(int now=1;now<=tt;++now)
	{
		int n;
		scanf("%d",&n);
		int tot=0;
		while(n--)
		{
			int t;
			scanf("%d",&t);
			tot+=(int)(ceil((double)t*1.1));
		}
		printf("Case #");
		printf("%d: %d\n",now,tot); 
	}
	return 0;
}
