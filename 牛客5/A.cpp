#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int l1,l2; 
	int t;
	scanf("%d%d%d",&l1,&l2,&t);
	for(int i=1;i<=t;++i)
	{
		double x,y;
		cin>>x>>y;
		double l=sqrt(x*x+y*y);
		if(l<=l1+l2&&l>=abs(l1-l2))
			printf("0.00000000\n");
		else if(l>l1+l2)
			printf("%.10lf\n",l-double(l1+l2));
		else
			printf("%.10lf\n",double(abs(l1-l2))-l);
	}
	return 0;
}
