#include<bits/stdc++.h>
using namespace std;
const double pi=3.14159265358979323846;
int main()
{
	int n,r,x,y;
	scanf("%d%d%d%d",&n,&r,&x,&y);
	double sita=pi/(double)n,len=(double)r*sin(sita)*2.0;
	if(x>y)swap(x,y);
	y-=x-1;
	x=1;
	int num=0;
	if(2*y>n)num=n-y+1;
	else num=y-1;
	printf("%.15lf\n",(double)num*len);
	return 0;
}
