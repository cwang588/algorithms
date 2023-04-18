#include<cstdio>
using namespace std;
int tu[10005][10005];
int ans;
int move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Q
{
	int x,y,t;
}q[10000005];
int n,m,X,Y;
bool usd[10005][10005];
int head=1,tail=1;
int main()
{
	scanf("%d%d%d%d",&n,&m,&X,&Y);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&tu[i][j]);
	q[1].x=1;
	q[1].y=1;
	q[1].t=0;
	usd[1][1]=true;
	while(!(head>tail))
	{
		if(X==q[head].x&&Y==q[head].y)
		{
			printf("%d",q[head].t);
			return 0;
		}
		for(int i=0;i<=3;++i)
		{
			if(q[head].x+move[i][0]>0&&q[head].y+move[i][1]>0)
			if(!usd[q[head].x+move[i][0]][q[head].y+move[i][1]]&&!tu[q[head].x+move[i][0]][q[head].y+move[i][1]])
			{
				++tail;
				q[tail].x=move[i][0]+q[head].x;
				q[tail].y=move[i][1]+q[head].y;
				q[tail].t=q[head].t+1;
				usd[move[i][0]+q[head].x][move[i][1]+q[head].y]=true;
			}
		}
		++head;
	}
	printf("%d",ans);
	return 0;
}
