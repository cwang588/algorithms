#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[2005][15];
struct edge
{
	int from,to,value;
}e[2000005];
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
int cnt,price[1005];
int fa[2005];
int getfa(int x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
int dis(int x,int y)
{
	int re=0;
	for(int i=0;i<7;++i)if(s[x][i]!=s[y][i])++re;
	return re;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		cnt=0;
		for(int i=1;i<=n;++i)fa[i]=i,cin>>s[i];
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				++cnt;
				e[cnt].value=dis(i,j);
				e[cnt].from=i;
				e[cnt].to=j;
			}
		sort(e+1,e+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans+=e[i].value;
				Merge(e[i].from,e[i].to);
			}
		}
		printf("The highest possible quality is 1/%d.\n",ans);
		scanf("%d",&n);
	}
	
	return 0;
}
