#include<bits/stdc++.h>
using namespace std;
char s[105][105];
bool usd[105][105];
int mov[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; 
int n,m;
void dfs(int x,int y)
{
	usd[x][y]=true;
	for(int i=0;i<4;++i)
	{
		int tox=x+mov[i][0],toy=y+mov[i][1];
		if(tox<=0||tox>n||toy<=0||toy>m||s[tox][toy]=='0'||usd[tox][toy])continue;
		dfs(tox,toy);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>s[i][j];
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!usd[i][j]&&s[i][j]!='0')
			{
				++ans;
				dfs(i,j);
			}
	printf("%d\n",ans);
	return 0;
}
