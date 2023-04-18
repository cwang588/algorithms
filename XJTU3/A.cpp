#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int T,n,m;
struct st
{
	int d,t;
}a[N];
bool cmp(st u,st v)
{
	return u.d<v.d;
}
int main()
{
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		int tp=0,ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i].d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i].t);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			tp+=a[i].t,++ans;
			if(tp>m)break;
		}
		if(tp>m)ans--;
		printf("Case %d: %d\n",j,ans);
	}
	return 0;
}
