#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n*m%2)
		return !printf("-1");
	if(n==1&&m==2)
		return !printf("RL");
	if(m==1&&n==2)
		return !printf("DU");
	if(n==1||m==1)
		return !printf("-1");	
	if(n%2==0)
	{
		for(int i=1;i<n;++i)
			printf("D");
		printf("R");
		for(int i=1;i<=n;++i)
		{
			if(i%2)
			{
				for(int j=1;j<m-1;++j)
					printf("R");
			}
			else
			{
				for(int j=1;j<m-1;++j)
					printf("L");
			}
			if(i!=n)
				printf("U");
			else
				printf("L");
		}
	}
	else
	{
		for(int i=1;i<m;++i)
			printf("R");
		printf("D");
		for(int i=1;i<=m;++i)
		{
			if(i%2)
			{
				for(int j=1;j<n-1;++j)
					printf("D");
			}
			else
			{
				for(int j=1;j<n-1;++j)
					printf("U");
			}
			if(i!=m)
				printf("L");
			else
				printf("U");
		}
	}	
	return 0;
}
