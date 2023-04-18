#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[10005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2; 
}
struct product
{
	int px,dx;
	bool operator < (const product &b)const
	{
		return px>b.px;
	}
}p[10005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int maxt=0;
		for(int i=1;i<=n;++i)cin>>p[i].px>>p[i].dx,maxt=max(maxt,p[i].dx);
		for(int i=1;i<=maxt;++i)fa[i]=i;
		sort(p+1,p+1+n);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int nowt=getfa(p[i].dx);
			if(nowt>0)
			{
				ans+=p[i].px;
				Merge(nowt,nowt-1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
