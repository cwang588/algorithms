#include<bits/stdc++.h>
using namespace std;
struct dis
{
	int d,id;
}d[100005];
int c[200005];
bool cmp(dis x,dis y)
{
	return x.d>y.d;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		d[i].id=i;
		scanf("%d",&d[i]);
	}
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<n;++i)
	{
		c[i]=2*d[i].id-1;
		printf("%d %d\n",c[i],2*(d[i+1].id)-1);
	}
	c[n]=2*d[n].id-1;
	int tail=n;
	for(int i=1;i<=n;++i)
	{
		printf("%d %d\n",2*d[i].id,c[d[i].d+i-1]);
		if(d[i].d+i-1==tail)
			c[++tail]=2*d[i].id;
	}
	return 0;
}
