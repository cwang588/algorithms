#include<cstdio>
#include<cmath>
using namespace std;
long long a[50][50];
int main()
{
	long long n,m,la=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			a[i][j]=(i*j)%3;
			la=a[i][j];
			a[i][j]%=3;
			if(a[i][j]<0)
				a[i][j]+=3;
		}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%lld ",a[i][j]);
		printf("\n");
	}
	return 0;
}
