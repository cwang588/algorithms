#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,x,a,b;
	cin>>n>>x>>a>>b;
	printf("%.2lf\n",n*((a-b)*x/100.0+b));
	
	return 0;
}
