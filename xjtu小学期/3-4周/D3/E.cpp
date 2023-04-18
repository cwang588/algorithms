#include<bits/stdc++.h>
using namespace std;
struct exam
{
	int a,b,s;
}e[200005];
int n;
bool judge(double x)
{
	double now=0.0;
	for(int i=1;i<=n;++i)
	{
		now+=(double)(e[i].s)/x;
		if(now>e[i].b)
			return false;
		now=max(now,(double)e[i].a);
	}
	return true;
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].s);
	double l=0.01,r=100000000000000000.0;
	while(r-l>0.0001)
	{
		double m=(r+l)/2.0;
		if(judge(m))
			r=m;
		else
			l=m;
	} 
	printf("%.2lf",l);
	return 0;
}
