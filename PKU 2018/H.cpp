#include<cstdio>
#include<cmath>
using namespace std;
int cl(int x)
{
	for(int i=2;i<=(int)sqrt(x);++i)
	{
		if(x%i==0)
		{
			while(x%i==0&&x!=i)
			{
				x/=i;
			}
			return cl(x);
		}
	}	
	return x;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		printf("%d\n",2147483647/cl(n));
		scanf("%d",&n);
	}
	return 0;
}
