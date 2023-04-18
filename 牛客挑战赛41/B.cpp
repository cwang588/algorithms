#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005];
int m=0,n=1;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)return !printf("-1\n");
	if(a==0)
	{
		if(b>1)return !printf("-1\n");
		return !printf("2 1\n1 2\n");
	}
	if(b==0)
	{
		for(int i=1;i<=a+1;++i)
		{
			x[++m]=n;
			y[m]=n+1;
			x[++m]=n;
			y[m]=n+2;
			x[++m]=n+1;
			y[m]=n+3;
			x[++m]=n+2;
			y[m]=n+3;
			n+=3;
		}
		printf("%d %d\n",n,m);
		for(int i=1;i<=m;++i)printf("%d %d\n",x[i],y[i]);
		return 0;
	}
	int t=min(a,b);
	for(int i=1;i<=t;++i)
	{
		++m;
		x[m]=n;
		y[m]=++n;
	}
	x[++m]=n;
	y[m]=n+1;
	x[++m]=n;
	y[m]=n+2;
	x[++m]=n+1;
	y[m]=n+2;
	n+=3;
	if(a>b)
	{
		x[++m]=2;
		y[m]=n;
		x[++m]=2;
		y[m]=n+1;
		x[++m]=n;
		y[m]=n+2;
		x[++m]=n+1;
		y[m]=n+2;
		n+=2;
		for(int i=1;i<=a-b;++i)
		{
			x[++m]=n;
			y[m]=n+1;
			x[++m]=n;
			y[m]=n+2;
			x[++m]=n+1;
			y[m]=n+3;
			x[++m]=n+2;
			y[m]=n+3;
			n+=3;
		}
	}
	else
	{
		for(int i=1;i<=b-a;++i)
		{
			x[++m]=2;
			y[m]=n++;
		}
		--n;
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i)printf("%d %d\n",x[i],y[i]);
	return 0;
}
