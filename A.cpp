#include<cstdio>
using namespace std;
int f[101][5000000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	f[1][0]=1;
	for(int i=1;i<=m;++i)
	{
		f[1][i]=(f[n][i-1]+f[2][i-1])%(1e9+7);
		for(int j=2;j<n;++j)
			f[j][i]=(f[j-1][i-1]+f[j+1][i-1])%(1e9+7);
		f[n][i]=(f[n-1][i-1]+f[1][i-1])%(1e9+7);
	}
	printf("%d",f[1][m]);
	return 0;
}
