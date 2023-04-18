#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int Move[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
#define N 2001000
int par[N],ran[N],ans[N],n,m,k,x,y,used[1100][1100];
char s[1100][1100];
int get(int a)
{
	if(a==par[a]) 
		return a;
	return par[a]=get(par[a]);
}
void unit(int a,int b)
{
	a=get(a);
	b=get(b);
	if(a==b) 
		return;
	if(ran[a]<ran[b]) 
		par[a]=b;
	else
	{
		par[b]=a;
		if(ran[a]==ran[b]) 
			ran[a]++;
	}
}
int dfs(int x,int y)
{
	used[x][y]=1;
	int ans=0,u=x*2000+y;
	for(int i=0;i<4;i++)
	{
		int x1=x+Move[i][0],y1=y+Move[i][1];
		if(x1<0||x1>=n||y1<0||y1>=m) continue;
		if(s[x1][y1]=='*') ans++;
		if(!used[x1][y1]&&s[x1][y1]=='.'){
			unit(u,x1*2000+y1);
			ans+=dfs(x1,y1);
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d%d\n",&n,&m,&k);
	for(int i=1;i<=N;i++)
		par[i]=i;
	memset(ran,0,sizeof(ran));
	memset(ans,0,sizeof(ans));
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++) 
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!used[i][j]&&s[i][j]=='.')
				ans[i*2000+j]=dfs(i,j);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		printf("%d\n",ans[get(x*2000+y)]);
	}
	return 0;
}
