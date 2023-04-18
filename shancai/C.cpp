#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=6*n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("*");
		for(int j=1;j<=4*n;++j)
			printf(" ");
		for(int j=1;j<=n;++j)
			printf("*");
		for(int j=1;j<=4*n;++j)
			printf(" ");
		for(int j=1;j<=n;++j)
			printf("*");
		printf("\n");
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf(" ");
		for(int j=1;j<=9*n;++j)
			printf("*");
		printf("\n"); 
	}
	
	return 0;
}
