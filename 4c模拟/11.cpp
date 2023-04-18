#include<cstdio>
using namespace std;
int n;
int mid[35],fro[35];
struct node
{
	int l,r;
}e[1005];
int f(int x)
{
	for(int i=1;i<=n;++i)
		if(mid[i]==x)
			return i;
}
void dfs(int now)
{
	int pos=f(now);
	for(int j=now+1;j<=n;++j)
		if(f(fro[j])<pos)
		{
			e[now].l=fro[j];
			dfs(fro[j]);
			break;
		}
	for(int j=now+1;j<=n;++j)
		if(f(fro[j])>pos)
		{
			e[now].r=fro[j];
			dfs(fro[j]);
			break;
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&mid[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&fro[i]);
	dfs(fro[1]);	
	return 0;
}
