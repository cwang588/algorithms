#include<cstdio>
using namespace std;
int ans[25][25];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	freopen("dabiao.txt","w",stdout);
	for(int i=1;i<=40;++i)
		for(int j=1;j<=40;++j)
		{
			int now=99999999;
			for(int k=0;k<=1000;++k)
			{
				if((i+k)*(j+k)/gcd(i+k,j+k)<now)
				{
					now=(i+k)*(j+k)/gcd(i+k,j+k);
					ans[i][j]=k;
				}
			}
		}
	for(int i=1;i<=40;++i)
	{
		for(int j=1;j<=40;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
