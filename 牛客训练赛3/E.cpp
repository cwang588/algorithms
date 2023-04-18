#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(m%2)
			printf("%d",n*m-2);
		else
			printf("%d",n*(m-1)-1);
		printf("\n");
	}
	return 0;
}
