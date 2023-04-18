#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=12;i>=2;--i)
	{
		int now=(int)pow((double)n,1.0/(double)i)-i/2;
		if(now<=1)
			continue;
		for(int j=now;;++j)
		{
			int ans=1;
			for(int k=0;k<i;++k)
				ans*=(k+j);
			if(n%ans==0)
			{
				printf("%d\n",i);
				for(int o=j;o<=j+i-1;++o)
				{
					if(o!=j+i-1)
						printf("%d*",o);
					else
						printf("%d",o);
				}
				return 0;
			}
			if(ans>n)
				break;
		}
	}
	printf("1\n%d",n);
	return 0;
}
