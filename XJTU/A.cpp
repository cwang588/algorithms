#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
string a[25],b[25];
int now; map<string,int>m;
struct edge
{
	int to,nxt;
}ed[505]; int Head[505],cnt;
void add(int x,int y)
{
	ed[++cnt].to=y;
	ed[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool dfn[5005],c,added[55][55];
void dfs(int x)
{
	if(c)return; dfn[x]=1;
	for(int u,i=Head[x];i;i=ed[i].nxt)
	{
		u=ed[i].to;
		if(dfn[u])c=1;
		else dfs(u);
		if(c)return;
	}
}
bool check()
{
	c=0;
	for(int i=1;i<=now;i++)dfn[i]=0;
	for(int i=1;i<=now;i++)
		if(!dfn[i])dfs(i);
	if(c)return 0; else return 1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cnt=now=0,m.clear();
		memset(Head,0,sizeof(Head));
		memset(added,0,sizeof(added));
		for(int i=1;i<=n;++i)
		{
			cin>>a[i]>>b[i];
			if(!m[a[i]]) m[a[i]]=++now;
			if(!m[b[i]]) m[b[i]]=++now;
		}
		bool ky=1;
		for(int i=1;i<=n;++i)
		{
			if(added[m[a[i]]][m[b[i]]])continue;
			add(m[a[i]],m[b[i]]),added[m[a[i]]][m[b[i]]]=1;
			if(!check())
			{
				cout<<a[i]<<' '<<b[i]<<endl;
				ky=0; break;
			}
		}
		if(ky) printf("0\n");
	}
	return 0;
}
/*
6
LandOverWind LonelyLight
FireMonk CutTheForest
CutTheForest LookCrazy
MakeFoxRush LetMeGo
HeroAunt UniqueLand
HeroAunt UniqueLand
*/
