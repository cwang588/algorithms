#include<bits/stdc++.h>
using namespace std;
double getdis(double xx1,double yy1,double zz1,double xx2,double yy2,double zz2)
{
	return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2)+(zz1-zz2)*(zz1-zz2));
} 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double oox,ooy,ooz,r;
		cin>>oox>>ooy>>ooz>>r;
		double sx,sy,sz,tx,ty,tz;
		cin>>sx>>sy>>sz>>tx>>ty>>tz;
		double ans=0.0;
		double l1=getdis(sx,sy,sz,oox,ooy,ooz),l2=getdis(tx,ty,tz,oox,ooy,ooz),l3=getdis(sx,sy,sz,tx,ty,tz);
		ans=sqrt(l1*l1-r*r)+sqrt(l2*l2-r*r);
		double ang1=acos((l1*l1+l2*l2-l3*l3)/(2*l1*l2));
		if(l1*l2*sin(ang1)>=r*l3)
		{
			printf("%.15lf\n",l3);
			continue;
		}
		double ang2=acos(r/l1),ang3=acos(r/l2);
		double ang=ang1-ang2-ang3;
		ans+=r*ang;
		printf("%.15lf\n",ans);
	}	
	return 0;
}
