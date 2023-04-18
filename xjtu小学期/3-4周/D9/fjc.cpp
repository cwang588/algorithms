#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
	return x*x*x*x+x*x/5.0-x+0.11;
}
int main()
{
	double x=0.0;
	for(;x<=2.0;x+=0.00001)
	{
		if(f(x)>=-0.00001&&f(x)<=0.00001)
			cout<<x<<endl;
	}
	return 0;
}
