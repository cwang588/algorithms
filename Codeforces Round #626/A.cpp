#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int num1=0,num2=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]%2==0)++num1;
			else ++num2;
		}
		if(!num1&&num2<2)printf("-1\n");
		else
		{
			if(num1)
			{
				printf("1\n");
				for(int i=1;i<=n;++i)
				{
					if(a[i]%2==0)
					{
						printf("%d\n",i);
						break;
					}
				}
			}
			else
				printf("2\n1 2\n");

		}
	}
	return 0;
}
