#include<cstdio>
#include<cstring>
using namespace std;
int f[10005][10005];
int main()
{
	for(int n=1;n<=10;++n)	
	{
		for(int k=n+1;k>=1;--k)	
		{
			memset(f,0,sizeof(f));
			f[1][1]=1;
			for(int i=1;i<=n+1;++i)
				for(int j=1;j<=n+1;++j)
					if((i!=1||j!=1)&&i-j<k)
						f[i][j]=f[i-1][j]+f[i][j-1];
			printf("%d ",f[n+1][n+1]);
		}
		printf("\n");
	}
	return 0;
}
