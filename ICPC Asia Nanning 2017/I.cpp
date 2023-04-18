#include<bits/stdc++.h>
using namespace std;
int a[10][10],k;
void leftcir(int x,int y)
{
	int tmp=a[x][y];
	a[x][y]=a[x][y+1];
	a[x][y+1]=a[x+1][y+1];
	a[x+1][y+1]=a[x+1][y];
	a[x+1][y]=tmp;
}
void rightcir(int x,int y)
{
	int tmp=a[x][y];
	a[x][y]=a[x+1][y];
	a[x+1][y]=a[x+1][y+1];
	a[x+1][y+1]=a[x][y+1];
	a[x][y+1]=tmp;
}
int dfs(int now)
{
	if(now==2*k+1)return 0;
	if(now%2)
	{
		int re=0; 
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
			{
				int tmp=0;
				for(int k=i;k<=i+1;++k)
					for(int o=j;o<=j+1;++o)
						tmp+=a[k][o];
				leftcir(i,j);
				re=max(re,tmp+dfs(now+1));
				rightcir(i,j);
			}
		return re;
	} 
	else
	{
		int re=9999999; 
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
			{
				int tmp=0;
				for(int k=i;k<=i+1;++k)
					for(int o=j;o<=j+1;++o)
						tmp+=a[k][o];
				leftcir(i,j);
				re=min(re,tmp+dfs(now+1));
				rightcir(i,j);
			}
		return re;
	} 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				scanf("%d",&a[i][j]);
		printf("%d\n",dfs(1));
	}
	return 0;
}
