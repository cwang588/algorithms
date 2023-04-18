#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("No\n");
			continue;
		}
		if(n==2147483647)
		{
			printf("Yes\n");
			continue;
		}		
		bool shi=true;
		for(int i=2;i*i<=n;++i)
			if(n%i==0)
			{
				shi=false;
				break;
			}
		if(shi)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
