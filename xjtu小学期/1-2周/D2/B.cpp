#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int l,r;
}q[1000050];
bool cmp(qj a,qj b)
{
	if(a.r!=b.r)
		return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&q[i].l,&q[i].r);
	sort(q+1,q+1+n,cmp);
	int ans=0,now=1;
	while(now<=n)
	{
		int t=q[now].r;
		++ans;
		++now;
		while(q[now].l<=t&&now<=n)
			++now;
	}
	printf("%d",ans);
	return 0;
}
