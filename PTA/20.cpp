#include<cstdio>
using namespace std;
bool you[100005],a[100005];
int ans[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		if(k>1)
		{
			for(int j=1;j<=k;++j)
			{
				int t;
				scanf("%d",&t);
				you[t]=true;
			}
		}
		else
		{
			int tt;
			scanf("%d",&tt);
		}
	}
	int m;
	scanf("%d",&m);
	int tot=0;
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(!you[t]&&!a[t])
		{
			ans[++tot]=t;
			a[t]=true;
		}
	}
	if(!tot)
		return !printf("No one is handsome");
	for(int i=1;i<=tot;++i)
	{
		if(i!=tot)
			printf("%05d ",ans[i]);
		else
			printf("%05d",ans[i]);
	}
	return 0;
}
