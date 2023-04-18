#include<cstdio>
#include<algorithm>
using namespace std;
int a[4005],mo[4005];
int jz[50][50];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*n;++i)
	{
		int t;
		scanf("%d",&t);
		++a[t];
	}
	int ji=0,er=0,si=0;
	for(int i=1;i<=1000;++i)
	{
		mo[i]=a[i]%4;
		if(mo[i]%2)
			++ji;
		if(mo[i]==2)
			++er;
		if(!mo[i])
			++si;
	}
	if(n%2==0&&ji)
		return !printf("NO");
	if(n%2&&ji>1)
		return !printf("NO");
	if(n%2==0&&er)
		return !printf("NO");
	if(n%2&&er>n/2*2)
		return !printf("NO");
	int x=1,y=0;
	if(n%2==0)
	{
		for(int i=1;i<=1000;++i)
		{
			while(a[i])
			{
				++y;
				if(y==n/2+1)
				{
					++x;
					y=1;
				}
				jz[x][y]=jz[n-x+1][y]=jz[x][n-y+1]=jz[n-x+1][n-y+1]=i;
				a[i]-=4;
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d ",jz[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(int i=1;i<=1000;++i)
		{
			while(a[i])
			{
				++y;
				if(y==n/2+1)
				{
					++x;
					y=1;
				}
				jz[x][y]=jz[n-x+1][y]=jz[x][n-y+1]=jz[n-x+1][n-y+1]=i;
				a[i]-=4;
			}
	}
	return 0;
}
