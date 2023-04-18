#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[2][200050];
int cnt1,cnt2,Head[2][100005],rd[2][100005],a[200005],fa[100005][25],dep[100005];
void add(int x,int y)
{
	++cnt1;
	e[0][cnt1].from=x;
	e[0][cnt1].to=y;
	e[0][cnt1].nxt=Head[0][x];
	Head[0][x]=cnt1;
	++cnt2;
	e[1][cnt2].from=y;
	e[1][cnt2].to=x;
	e[1][cnt2].nxt=Head[1][y];
	Head[1][y]=cnt2;
	++rd[0][y];
	++rd[1][x];
}
queue<int>q;
int lg[1100005];
void init()
{
	for(int i=1;i<=1000001;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x][lg[dep[x]-dep[y]]-1];
	if(x==y)return x;
	for(int k=lg[dep[x]]-1;k>=0;--k)
	{
		if(fa[x][k]!=fa[y][k])
		{
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	return fa[x][0];
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(Head,0,sizeof(Head));
		memset(rd,0,sizeof(rd));
		memset(fa,0,sizeof(fa));
		cnt1=cnt2=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;++i)if(!rd[1][i])add(i,n+1);
		dep[n+1]=0;
		q.push(n+1);
		int tot=0;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			a[++tot]=now;
			for(int i=Head[1][now];i;i=e[1][i].nxt)
			{
				int to=e[1][i].to;
				--rd[1][to];
				if(!rd[1][to])q.push(to);
			}
		}
		for(int i=2;i<=tot;++i)
		{
			int tmp=0;
			for(int j=Head[0][a[i]];j;j=e[0][j].nxt)
			{
				int to=e[0][j].to;
				if(!tmp)tmp=to;
				else tmp=LCA(tmp,to);
			}
			dep[a[i]]=dep[tmp]+1;
			fa[a[i]][0]=tmp;
			for(int k=1;k<=19;++k)fa[a[i]][k]=fa[fa[a[i]][k-1]][k-1];
		}
		int Q;
		scanf("%d",&Q);
		while(Q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",dep[x]+dep[y]-dep[LCA(x,y)]);
		}
	}
	return 0;
}
