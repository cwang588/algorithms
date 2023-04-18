#include<cstdio>
using namespace std;
int beh[35],mid[35],n,l[35],r[35],re;
bool usd[35];
int dfs(int l1,int r1,int l2,int r2)
{
	if(l1>r1)
		return 0;
	int p=l1,root=beh[r2];
	while(mid[p]!=root)
		++p;
	l[root]=dfs(l1,p-1,l2,l2+p-l1-1);
	r[root]=dfs(p+1,r2,l2+p-l1,r2-1);
	return root;
}
void bfs(int now)
{
	if(now<1||now>n)
		return;
	--re;
	if(re)
		printf("%d ",now);
	else
	{
		printf("%d\n",now);
		return;
	}
	bfs(l[now]);
	bfs(r[now]);
}	
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&beh[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&mid[i]);
	dfs(1,n,1,n);
	re=n;
	bfs(beh[n]);
	return 0;
}
