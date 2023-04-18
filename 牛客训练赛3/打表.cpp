#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	for(int i=3;i<=63;++i)
	{
		for(int j=1;j<=log(i);++j)
		{
			if(i&(1<<j))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	
	
	
	return 0;
}
