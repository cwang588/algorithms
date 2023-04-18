#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char c[505][505];
bool usd[505][505][2];
int qu[505];
int mm[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int num,int x,int y,int fx)
{
	if(x==n+1)
	{
		qu[num]=y;
		return;
	}
	if(y==m+1||y==0||x==0)
	{
		qu[num]=-1;
		return;
	}
	if(c[x][y]=='.')
	{
		dfs(num,x+mm[fx][0],y+mm[fx][1],fx);
	}
	else if(c[x][y]=='/')
	{
		if(fx==0||fx==2)
		{
			if(usd[x][y][0])
			{
				qu[num]=-1;
				return;
			}
			else
			{
				usd[x][y][0]=true;
				if(fx==0)
					dfs(num,x,y-1,3);
				else
					dfs(num,x-1,y,1);
			}
		}
		if(fx==1||fx==3)
		{
			if(usd[x][y][1])
			{
				qu[num]=-1;
				return;
			}
			else
			{
				usd[x][y][1]=true;
				if(fx==1)
					dfs(num,x,y+1,2);
				else
					dfs(num,x+1,y,0);
			}			
		}		
	}
	else
	{
		if(fx==0||fx==3)
		{
			if(usd[x][y][0])
			{
				qu[num]=-1;
				return;
			}
			else
			{
				usd[x][y][0]=true;
				if(fx==0)
					dfs(num,x,y+1,2);
				else
					dfs(num,x-1,y,1);
			}
		}
		if(fx==1||fx==2)
		{
			if(usd[x][y][1])
			{
				qu[num]=-1;
				return;
			}
			else
			{
				usd[x][y][1]=true;
				if(fx==1)
					dfs(num,x,y-1,3);
				else
					dfs(num,x+1,y,0);
			}			
		}		
	}
}
int main()
{
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>c[i][j];
	for(int i=1;i<=m;++i)
	{
		memset(usd,false,sizeof(usd));
		dfs(i,1,i,0);	
		printf("%d\n",qu[i]);
	}
	return 0;
} 
