#include<cstdio>
using namespace std;
int n,m,l,t,num,move[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bool zl[2500][250][150],usd[2500][250][150];
void dfs(int x,int y,int z)
{
	if(x<1||x>n||y<1||y>m||z<1||z>l)
		return;
	++num;
	usd[x][y][z]=true;
	for(int i=0;i<6;++i)
		if(zl[x+move[i][0]][y+move[i][1]][z+move[i][2]]&&!usd[x+move[i][0]][y+move[i][1]][z+move[i][2]])
			dfs(x+move[i][0],y+move[i][1],z+move[i][2]);	
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&l,&t);
	for(int k=1;k<=l;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int tt;
				scanf("%d",&tt);
				if(!tt)
					zl[i][j][k]=false;
				else
					zl[i][j][k]=true;	
			}	
	int ans=0;	
	for(int k=1;k<=l;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				num=0;	
				if(zl[i][j][k]&&!usd[i][j][k])
				{
					dfs(i,j,k);
					if(num>=t)
						ans+=num;
				}
			}
	printf("%d",ans);
	return 0;
}
