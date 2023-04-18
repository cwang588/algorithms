#include<cstdio>
#define v 2997925
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int n=1,now=x;
		for(n=1;;++n)
		{
			now=now*2+y;
			if(now>=v)
				break;
		}
		printf("%d\n",n);
	}
	return 0;
}
