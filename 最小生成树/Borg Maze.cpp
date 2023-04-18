#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char s[105][105];
int xx[105],yy[105];
bool usd[105][105];
struct edge
{
	int from,to,value;
}e[200005];
int cnt,fa[105],Move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
struct node
{
	int x,y,dis;
	node(int xx,int yy,int diss)
	{
		x=xx;
		y=yy;
		dis=diss;
	}
};
int numm[105][105];
queue<node>q;
bool cmp(edge a,edge b)
{
	return a.value<b.value;
}
char str[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(numm,0,sizeof(numm));
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));
		memset(s,0,sizeof(s));
		memset(usd,0,sizeof(usd));
		cnt=0;
		int x,y,num=0;
		cin>>x>>y;
		gets(str);
		for(int i=1;i<=y;++i)
		{
			for(int j=1;j<=x;++j)
			{
				scanf("%c",&s[i][j]);
				if(s[i][j]=='S'||s[i][j]=='A')
				{
					++num;
					xx[num]=i;
					yy[num]=j;
					numm[i][j]=num;
				}
			}
			getchar();
		}
		for(int i=1;i<=num;++i)fa[i]=i;
		for(int i=1;i<=num;++i)
		{
			memset(usd,0,sizeof(usd));
			usd[xx[i]][yy[i]]=true;
			q.push(node(xx[i],yy[i],0));
			while(!q.empty())
			{
				node tmp=q.front();
				q.pop();
				int nowx=tmp.x,nowy=tmp.y;
				if(s[nowx][nowy]=='A'||s[nowx][nowy]=='S')
				{
					++cnt;
					e[cnt].from=i;
					e[cnt].to=numm[nowx][nowy];
					e[cnt].value=tmp.dis;
				}
				for(int j=0;j<4;++j)
				{
					int tox=nowx+Move[j][0],toy=nowy+Move[j][1];
					if(tox>0&&tox<=y&&toy>0&&toy<=x&&!usd[tox][toy]&&s[tox][toy]!='#')
					{
						usd[tox][toy]=true;
						q.push(node(tox,toy,tmp.dis+1));
					}
				}
			}
		}
		int ans=0;
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans+=e[i].value;
				fa[r1]=r2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
