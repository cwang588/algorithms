#include<bits/stdc++.h>
using namespace std;
int a,b;
int dp(int x,int y)
{
	if(x==0&&y==0)return 0;
	if(x==0)
	{
		if(y>0)return dfs(x,y-1)+b;
		else return dfs(x,y+1)+b;
	}
	if(y==0)
	{
		if(x>0)return dfs(x-1,y)+b;
		else return dfs(x+1,y)+b;
	}
	if(x>0)
	{
		if(y>0)
	}
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=-10;i<=10;++i)	
	{
		for(int j=-10;j<=10;++j)printf("%d ",dp(i,j));
		printf("\n");
	}
	return 0;
} 
