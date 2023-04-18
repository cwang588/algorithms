#include<bits/stdc++.h>
using namespace std;
int fa[200005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
int cnt[200005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2)Merge(r1,r2);
	}
	for(int i=1;i<=n;++i)getfa(i),++cnt[fa[i]];
	int ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}
