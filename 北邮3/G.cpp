#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
double pi=3.1415927;
int main()
{
	long long xx1,xx2,yy1,yy2,r1,r2;
	scanf("%lld%lld%lld%lld%lld%lld",&xx1,&yy1,&r1,&xx2,&yy2,&r2);
	long long dis=(xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2);
	if((r1+r2)*(r1+r2)<=(xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2))
		return !printf("0.00000000000000000000");
	if((r1-r2)*(r1-r2)>=dis)
		return !printf("%.20lf",pi*min(r1,r2)*min(r1,r2));
	double c=sqrt((double)dis),p=(r1+r2+c)/2,s;
	s=sqrt((double)p*(p-r1)*(p-r2)*(p-c));
	double ans=asin((double)2*s/r1/c)*r1*r1+asin((double)2*s/r2/c)*r2*r2-2*s;
	printf("%.20lf",ans);
	return 0;
}
