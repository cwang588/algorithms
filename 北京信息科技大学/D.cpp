#include<bits/stdc++.h>
using namespace std;
char a[35][35];
bool usd[35][35];
int Move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct now
{
	int x,y,dis;
};
queue<now>q; 
int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	now s;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='k')
			{
				s.x=i;
				s.y=j;
				s.dis=0;
			}
		}
	q.push(s);
	int ans=99999999;
	while(!q.empty())
	{
		now Now=q.front();
		q.pop();
		if(a[Now.x][Now.y]=='e')
		{
			if(!usd[Now.x][Now.y])
			{
				++cnt;
				ans=min(ans,Now.dis);
			}
			usd[Now.x][Now.y]=true;
			continue;
		}
		usd[Now.x][Now.y]=true;
		for(int i=0;i<4;++i)
		{
			int xx=Now.x+Move[i][0],yy=Now.y+Move[i][1],d=Now.dis;
			if(xx<=n&&xx>=1&&yy>=1&&yy<=m&&!usd[xx][yy]&&a[xx][yy]!='*')
			{
				now t;
				t.x=xx;
				t.y=yy;
				t.dis=d+1;
				q.push(t);
			}
		} 
	}
	if(!cnt)
		return !printf("-1\n");
	printf("%d %d\n",cnt,ans);
	return 0;
}
