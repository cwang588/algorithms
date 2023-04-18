#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=min(a[x],a[y]);
	}
	printf("%d",ans);
	return 0;
}
