#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char t;
		double h;
		cin>>t>>h;
		if(t=='M')
			printf("%.2lf\n",(double)h/1.09);
		else
			printf("%.2lf\n",(double)h*1.09);	
	}
	return 0;
}
