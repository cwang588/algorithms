#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char qp[25][25];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(qp,' ',sizeof(qp));
		for(int i=1;i<=19;++i)
			for(int j=1;j<=19;++j)
				qp[i][j]='.';
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			char col;
			int x,y;
			cin>>col;
			scanf("%d%d",&x,&y);
			if(qp[x][y]!='.')
			{
				printf("miss 1\n");
				continue;
			}
			qp[x][y]=col;
			
		}
	}
	
	return 0;
}
