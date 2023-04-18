#include<bits/stdc++.h>
using namespace std;
int fa[100005];	
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
int a[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long X1=0,X2=0,Y1=0,Y2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			fa[i]=i;
			if(a[i]==1)++X1;
			else ++X2;
		}
		printf("%lld\n",calc(X1,X2,0,0));
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(a[x]==1)
			{
				--[x]
			}
		}
	}
	return 0;
}
