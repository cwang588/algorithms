#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int n,m;
int hang(int x)
{
	int re=0;
	for(int i=1;i<=m;++i)re+=a[x][i];
	return re;
}
int lie(int x)
{
	int re=0;
	for(int i=1;i<=n;++i)re+=a[i][x];
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=1;k<=m;++k)
				for(int o=k+1;o<=m;++o)
				{
					ans=max(ans,hang(i)+hang(j)+lie(k)+lie(o)-a[i][k]-a[i][o]-a[j][k]-a[j][o]);
				}	
	printf("%d\n",ans);
	return 0;
}
