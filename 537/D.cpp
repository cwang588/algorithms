#include<cstdio>
#include<iostream>
using namespace std;
char tu[1005][1005];
int s[10];
int num[10],tot[10];
bool ran=true;
int n,m,p;
struct a
{
	int x,y;
}q[10][1000000];
int mmove[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int x,int y,int pp,int re)
{
	if(!re)
		return;
	for(int i=0;i<4;++i)
	{
		int xx=x+mmove[i][0],yy=y+mmove[i][1];
		if(xx>0&&yy>0&&xx<=n&&yy<=m&&tu[xx][yy]!='#'&&(tu[xx][yy]<='0'||tu[xx][yy]>'9'))
		{
			tu[xx][yy]='0'+pp;
			++tot[pp];
			ran=true;
			q[tu[xx][yy]-'0'][tot[tu[xx][yy]-'0']].x=xx;
			q[tu[xx][yy]-'0'][tot[tu[xx][yy]-'0']].y=yy;
			bfs(xx,yy,pp,re-1);
		}
	}
}
void ep(int p,int sum)
{
	bfs(q[p][sum].x,q[p][sum].y,p,num[p]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i)
		scanf("%d",&s[p]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>tu[i][j];
			if(tu[i][j]>'0'&&tu[i][j]<='9')
			{
				++num[tu[i][j]-'0'];
				++tot[tu[i][j]-'0'];
				q[tu[i][j]-'0'][num[tu[i][j]-'0']].x=i;
				q[tu[i][j]-'0'][num[tu[i][j]-'0']].y=j;
			}
		}
	while(ran)
	{
		ran=false;
		for(int i=1;i<=p;++i)
		{
			int tt=tot[i];
			for(int j=1;j<=tt;++j)
				ep(i,j);
		}
	}
	for(int i=1;i<=p;++i)
		printf("%d ",tot[i]);
	return 0;
}
