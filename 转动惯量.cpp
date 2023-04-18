#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	double x=0.0306/4.0/3.14/3.14;
	double t;
	while(cin>>t)
	{
		cout<<(x*t*t-0.0005406)/25.0<<endl;
	}
	return 0;
}
