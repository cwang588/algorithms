#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	printf("%d %d\n",x,y);
	int lx=x,ly=y;
	for(int i=1;i<=n;++i)
	{
		if(i==x)continue;
		printf("%d %d\n",i,y);
		lx=i;
	}
	for(int i=1;i<=m;++i)
	{
		if(i==y)continue;
		printf("%d %d\n",lx,i);
		ly=i;
		int tmp=lx;
		for(int j=1;j<=n;++j)
		{
			if(j==tmp)continue;
			printf("%d %d\n",j,i);
			lx=j;
		}
	}
	return 0;
}
