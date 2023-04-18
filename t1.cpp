#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d ",m);
		if(n==0||m==0)
		{
			printf("0\n");
			continue;
		}
		
		if(n-m>=m)
			printf("1\n");
		else
		{
			if(m%(n-m+1)==0)
				printf("%d\n",m/(n-m+1));
			else
				printf("%d\n",m/(n-m+1)+1);
		}
	}
	return 0;
} 
