#include<bits/stdc++.h>
using namespace std;
const int N=105;
double x[N],y[N],l[N],xita[N];
double calc(int num)
{
	return sqrt((x[1]-x[num])*(x[1]-x[num])+(y[1]-y[num])*(y[1]-y[num]));
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double r;
	cin>>n>>r;
	for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
	x[n+1]=x[1];
	y[n+1]=y[1];
	for(int i=1;i<=n;++i)l[i]=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
	for(int i=2;i<=n;++i)
	{
		double tl=sqrt((x[i+1]-x[i-1])*(x[i+1]-x[i-1])+(y[i+1]-y[i-1])*(y[i+1]-y[i-1]));
		xita[i]=acos((l[i-1]*l[i-1]+l[i]*l[i]-tl*tl)/(2*l[i]*l[i-1]));
	}
	double ans=0;
	for(int i=2;i<=n;++i)
	{
		double t=acos(l[i-1]/(2*r))+acos(l[i]/(2*r));
		ans+=calc(i)*(t-xita[i]);
	}
	printf("%.15lf\n",ans);
	return 0;
}
