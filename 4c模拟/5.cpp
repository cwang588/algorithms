#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int t=a*b;
	bool tou=true;
	while(t)
	{
		if(t%10)
		{
			printf("%d",t%10);
			tou=false;
		}
		else
		{
			if(!tou)
				printf("0");
		}
		t/=10;
	}
	return 0;
}
