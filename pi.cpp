#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double a=2.0;
	for(int i=1;i<=n;++i)
	{
		a*=(double)(4*i*i);
		a/=(double)((2*i-1)*(2*i+1));
	}
	cout<<a;
	
	return 0;
}
