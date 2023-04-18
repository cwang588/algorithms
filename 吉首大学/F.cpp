#include<bits/stdc++.h>
using namespace std;
const double pi=3.1415926535898;
int main()
{
	int n;
	while(cin>>n)
	{
		double tt=(1.0-2.0/(double)n)/2.0;
		double t=sin(tt*pi);
		printf("%.2lf\n",100.0*(double)n/((double)1.0-t));
	}
	
	return 0;
}
