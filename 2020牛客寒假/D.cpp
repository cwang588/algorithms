#include<bits/stdc++.h>
using namespace std;
double jdz(double x)
{
	return x>0.0?x:-x;
}
double mi(double x)
{
	return x>=0.0?pow(x,1.0/3.0):-pow(-x,1.0/3.0);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		double a,b;
		cin>>a>>b;
		double t=0.0,now=a;
		if((b>0&&a>b)||(b<0&&a<b))
		{
			while(jdz(mi(now)-b)+1.0<jdz(now-b)&&jdz(now)>jdz(b))
			{
				now=mi(now);
				t+=1.0;
			}
			t+=jdz(now-b);
			now=b;
		}
		else if(a*b<=0.0)
		{
			while(jdz(mi(now))+1.0<jdz(now))
			{
				now=mi(now);
				t+=1.0;
			}
		}
		else;
		t+=jdz(now-b);
		printf("%.15lf\n",t);
	}
	return 0;
}
