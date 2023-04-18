#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char t;
	cin>>a>>t>>b;
	double now1=(a%12)*30+b*0.5,now2=b*6;
	if(abs(now1-now2)<=180)printf("%.1lf\n",abs(now1-now2));
	else printf("%.1lf\n",360-abs(now1-now2));
	return 0;
}
