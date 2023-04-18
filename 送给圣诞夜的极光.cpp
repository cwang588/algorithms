#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
char sky[105][105];
bool tu[105][105];
int move[12][2]={{2,0},{1,1},{1,0},{1,-1},{0,2},{0,1},{0,-1},{0,-2},{-1,-1},{-1,1},{-1,0},{-2,0}};
int tot;
int n,m;
void dfs(int x,int y)
{
	tu[x][y]=true;
	for(int i=x-2;i<=x+2;i++)
		for(int j=y-2;j<=y+2;j++)
		{
			if(i==x&&j==y)
				continue;
			if(abs(x-i)+abs(y-j)<=2&&!tu[i][j]&&sky[i][j]=='#')
				dfs(i,j);
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	
		for(int j=1;j<=m;++j)	
			cin>>sky[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(sky[i][j]=='#'&&!tu[i][j])
			{
				++tot;
				dfs(i,j);
			}
	printf("%d",tot);
	return 0;
}
