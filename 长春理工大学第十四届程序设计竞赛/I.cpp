#include<bits/stdc++.h>
using namespace std;
struct fgo
{
	bool chou;
	int id;
	double num;
}a[20005];
bool cmp1(fgo x,fgo y)
{
	return x.num>y.num;
}
bool cmp2(fgo x,fgo y)
{
	return x.id<y.id;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	n/=3;
	for(int i=1;i<=m;++i)
	{
		scanf("%lf",&a[i].num);
		a[i].id=i;
		a[i].chou=false;
	}
	for(int i=1;i<=m;++i)
	{
		double t;
		cin>>t;
		a[i].num*=t;
	}
	sort(a+1,a+1+m,cmp1);
	for(int i=1;i<=n;++i)
		a[i].chou=true;
	sort(a+1,a+1+m,cmp2);
	for(int i=1;i<=m;++i)
	{
		if(a[i].chou)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}
