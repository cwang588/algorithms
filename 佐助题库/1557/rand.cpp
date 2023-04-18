#include<bits/stdc++.h>
using namespace std;
bool usd[405][105];
int main()
{
	srand((unsigned)time(0));
	freopen("10.in","w",stdout);
	int n=50;
	printf("%d\n",n);
	int num=rand()%(n*n)+1;
	for(int i=1;i<=num;++i)
	{
		int x=rand()%n+1,y=rand()%n+1;
		while(usd[x][y])
		{
			x=rand()%n+1;
			y=rand()%n+1;
		}
		usd[x][y]=true;
		printf("%d %d %d\n",x,y,rand()%50+1);
	}
	printf("0 0 0\n");
	return 0;
}
