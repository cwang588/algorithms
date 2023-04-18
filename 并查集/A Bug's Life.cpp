#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int fa[1000005],value[1000005];
int getfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=getfa(fa[x]);
		value[x]^=value[t];
	}
	return fa[x];
}
void Merge(int x,int y,int z)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	value[r1]=value[y]^value[x]^z;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int scenario=1;scenario<=t;++scenario)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)fa[i]=i,value[i]=0;
		bool ky=true;
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int r1=getfa(x),r2=getfa(y);
			if(r1==r2)
			{
				if(value[x]^value[y]==0)
					ky=false;
			}
			else Merge(x,y,1);
		}
		printf("Scenario #%d:\n",scenario);
		if(ky)printf("No suspicious ");
		else printf("Suspicious ");
		printf("bugs found!\n\n");
	}
	return 0;
}
