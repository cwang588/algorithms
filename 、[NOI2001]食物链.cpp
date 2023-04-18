#include<bits/stdc++.h>
using namespace std;
int fa[150005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;++i)fa[i]=i;
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
			if(getfa(x)==getfa(y+n)||getfa(x+n)==getfa(y))++ans;
			else
			{
				fa[getfa(x)]=getfa(y);
				fa[getfa(x+n)]=getfa(y+n);
				fa[getfa(x+2*n)]=getfa(y+2*n);
			}
		}
		else
		{
			if(x==y||getfa(x)==getfa(y)||getfa(y)==getfa(x+n))++ans;
			else
			{
				fa[getfa(x)]=getfa(y+n);
				fa[getfa(x+n)]=getfa(y+2*n);
				fa[getfa(x+2*n)]=getfa(y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
