#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int l,r;
}q[100005];
int col[100005];
bool cmp(qj a,qj b)
{
	return a.l<b.l;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&col[i]);
	for(int i=1;i<=n;++i)
		if(!q[col[i]].l)
			q[col[i]].l=i;
	for(int i=n;i>=1;--i)
		if(!q[col[i]].r)
			q[col[i]].r=i;
	for(int i=1;i<=m;++i)
	{
		if(!q[i].l)
			printf("%d %d\n",q[m].l,q[m].r);
		else
			printf("%d %d\n",q[i].l,q[i].r);
	}
	return 0;
}
