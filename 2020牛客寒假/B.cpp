#include<bits/stdc++.h>
using namespace std;
const double eps=0.00000001;
struct point
{
	int x,y;
}p[100005];
double jdz(double x)
{
	return x>0.0?x:-x;
}
int n;
bool check(double len)
{
	double nowl=-300000.0,nowr=300000.0;
	for(int i=1;i<=n;++i)
	{
		if(jdz(p[i].y)>len)return false;
		double t=p[i].x*p[i].x+p[i].y*p[i].y-len*len;
		double tl=p[i].x-sqrt(p[i].x*p[i].x-t);
		double tr=p[i].x+sqrt(p[i].x*p[i].x-t);
		if(tr<nowl||tl>nowr)return false;
		nowl=max(nowl,tl);
		nowr=min(nowr,tr);
		if(nowl>nowr)return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);	
	double l=0.0,r=15000.0;
	while(jdz(r-l)>eps)
	{
		double m=(l+r)/2.0;
		if(check(m))r=m;
		else l=m;
	}
	printf("%.15f\n",r);
	return 0;
}
