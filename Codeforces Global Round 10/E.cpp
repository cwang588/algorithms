#include<bits/stdc++.h>
using namespace std;
long long a[55][55];
int x[105],y[105];
int main()
{
	int n;
	scanf("%d",&n);
	a[1][1]=0;
	long long now=1,noww=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{	
			if(j%2)a[i][j]=now;
			now*=2;
		}
		now=noww*2;
		noww=now;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%lld ",a[i][j]);
		printf("\n");
		fflush(stdout);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long tot;
		scanf("%lld",&tot);
		int num=0,nowx=n,nowy=n;
		x[++num]=n;
		y[num]=n;
		tot-=a[n][n];
		for(int i=1;i<=2*n-2;++i)
		{
			if(nowx==1)--nowy;
			else if(nowy==1)--nowx;
			else
			{
				if(tot>=a[nowx-1][nowy]&&tot>=a[nowx][nowy-1])
				{
					if(a[nowx-1][nowy]>a[nowx][nowy-1])--nowx;
					else --nowy;
				}
				else if(tot>=a[nowx-1][nowy])--nowx;
				else --nowy;
			}
			tot-=a[nowx][nowy];
			++num;
			x[num]=nowx;
			y[num]=nowy;
		}	
		for(int i=num;i>=1;--i)
		{
			printf("%d %d\n",x[i],y[i]);
			fflush(stdout);
		}
	}
	return 0;
}
