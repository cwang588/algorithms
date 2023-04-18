#include<cstdio>
using namespace std;
int a[505][505],b[505][505],n,m;
int c1[250005],c2[250005],r1[250005],r2[250005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			c1[n*(i-1)+j-1]=a[i][j];
			r1[m*(j-1)+i-1]=a[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&b[i][j]);
			c2[n*(i-1)+j-1]=b[i][j];
			r2[m*(j-1)+i-1]=b[i][j];
		}
	bool cc1,cc2,rr1,rr2;
	cc1=cc2=rr1=rr2=false;
	int sum1,sum2,sum3,sum4;
	sum1=sum2=sum3=sum4;
	for(int i=1;i<=n*m;++i)
	{
		if(c1[i]==1)
			++sum1;
		else
		{
			if(sum1%2)
				cc1=!cc1;
		}
	}
	for(int i=0;i<n*m;++i)
	{
		if(c2[i]==1)
			++sum2;
		else
		{
			if(sum2%2)
				cc2=!cc2;
		}
	}
	for(int i=1;i<=n*m;++i)
	{
		if(r1[i]==1)
			++sum3;
		else
		{
			if(sum3%2)
				rr1=!rr1;
		}
	}
	for(int i=1;i<=n*m;++i)
	{
		if(r2[i]==1)
			++sum4;
		else
		{
			if(sum4%2)
				rr2=!rr2;
		}
	}	
	if(cc1==cc2&&rr1==rr2)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
