#include<bits/stdc++.h>
using namespace std;
bool ky[500005];
int fa[500005];
int n,k,m;
int getfa(int x)
{
	if(fa[x]==x)
		return fa[x];
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void Mergefa(int a,int b)
{
	fa[b]=a;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int Fa=getfa(a),Fb=getfa(b);
		if(Fa==Fb)
			continue;
		Mergefa(Fa,Fb);
		ky[i]=true;
		++ans;
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;++i)
		if(ky[i])
			printf("%d ",i);
	return 0;
}
