#include<bits/stdc++.h>
using namespace std;
struct qq
{
	long long a,b,c,d;
	int k;
}q[105];
bool cmp(qq x,qq y)
{
	return x.k<y.k;
}
long long ans;
int n,k;
void dfs(int now,long long nowa,long long nowb,long long nowc,long long nowd)
{
	if(now>n)
	{
		ans=max(ans,nowa*nowb*nowc*nowd);
		return;
	}
	int r=now+1;
	while(q[r].k==q[r-1].k)++r;
	for(int i=now;i<r;++i)dfs(r,nowa+q[i].a,nowb+q[i].b,nowc+q[i].c,nowd+q[i].d);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&n,&k);	
		for(int i=1;i<=n;++i)scanf("%d%lld%lld%lld%lld",&q[i].k,&q[i].a,&q[i].b,&q[i].c,&q[i].d);			
		sort(q+1,q+n+1,cmp);
		dfs(1,100,100,100,100);
		printf("%lld\n",ans);
	}
	return 0;
}
