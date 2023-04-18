#include<cstdio>
using namespace std;
int main()
{
	int t,mod;
	scanf("%d%d",&t,&mod);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int i=1;
		while(x%mod&&y&&mod&&i<=1e5)
		{
			if(i%2)
				x=(x+y)%mod;
			else
				y=(x+y)%mod;
			++i;
		}
		if(i>1e5)
			printf("error\n");
		else
		{
			if(x%mod==0)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
} 
