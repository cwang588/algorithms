#include<bits/stdc++.h>
using namespace std;
struct work
{
	int e,t;
}w[1005];
bool cmp(work a,work b)
{
	return a.e>b.e;
}
int main()
{
//	freopen("zz15189.in","r",stdin);
//	freopen("zz15189.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&w[i].t,&w[i].e);
	sort(w+1,w+1+n,cmp);
	int now=2147483647;
	for(int i=1;i<=n;++i)now=min(now-w[i].t,w[i].e-w[i].t);
	printf("%d\n",now>=0?now:-1);
	return 0;
}
