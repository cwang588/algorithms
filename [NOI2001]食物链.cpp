#include<bits/stdc++.h>
using namespace std;
int fa[50005],value[50005];
int getfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=getfa(fa[x]);
		value[x]=(value[x]+value[t]+3)%3;
	}
	return fa[x];
}
void merge(int x,int y,int z)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	value[r1]=(value[y]+z-value[x]+3)%3;
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=k;++i)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(x>n||y>n)
		{
			++ans;
			continue;
		}
		if(t==1)
		{
			int r1=getfa(x),r2=getfa(y);
			if(r1!=r2)merge(x,y,0);
			else if((value[x]-value[y]+3)%3)++ans;
		}
		else
		{
			int r1=getfa(x),r2=getfa(y);
			if(r1!=r2)merge(x,y,1);
			else if((value[x]-value[y]+3)%3!=1)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
