#include<bits/stdc++.h>
using namespace std;
int n,m;
int pl[50];
int move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dis[15][15];
struct zb
{
	int x,y;
}z[55505];
queue<pair<zb,int> >q;
bool usd[55][55];
struct des
{
	int x,y;
}d[15];
int num;
char a[55][55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='@')
			{
				++num;
				d[num].x=i;
				d[num].y=j;
			}	
			if(a[i][j]=='p')
			{
				d[0].x=i;
				d[0].y=j;
			}
		}
	for(int i=0;i<=num;++i)
	{
		memset(usd,false,sizeof(usd));
		usd[d[i].x][d[i].y]=true;
		zb tt;
		tt.x=d[i].x;
		tt.y=d[i].y;
		q.push(make_pair(tt,0));
		while(!q.empty())
		{
			int dd=q.front().second;
			zb ttt=q.front().first;
			int nx=ttt.x,ny=ttt.y;
			q.pop();
			if(a[nx][ny]=='p')
				dis[0][i]=dis[i][0]=dd;
			if(a[nx][ny]=='@')
			{
				for(int j=1;j<=num;++j)
					if(d[j].x==nx&&d[j].y==ny)
					{
						dis[i][j]=dis[j][i]=dd;
						break;
					}
			}
			for(int j=0;j<=3;++j)
			{
				int xx=nx+move[j][0],yy=ny+move[j][1];
				if(xx>0&&xx<=n&&yy>0&&yy<=m&&!usd[xx][yy]&&a[xx][yy]!='#')
				{
					usd[xx][yy]=true;
					zb tttt;
					tttt.x=xx;
					tttt.y=yy;
					q.push(make_pair(tttt,dd+1));
				}
			}
		}
	}
	for(int i=1;i<=num;++i)
		if(!dis[0][i])
			return !printf("-1");
	for(int k=0;k<=num;++k)
		for(int i=0;i<=num;++i)
			for(int j=0;j<=num;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);	
	int ans=0;
	for(int i=1;i<=num;++i)
		pl[i]=i;
	for(int i=1;i<=num;++i)
		ans+=dis[i-1][i];
	while(next_permutation(pl+1,pl+1+num))
	{
		int tot=0;
		for(int i=1;i<=num;++i)
			tot+=dis[pl[i-1]][pl[i]];
		ans=min(ans,tot);		
	}
	printf("%d",ans);
	return 0;
}
