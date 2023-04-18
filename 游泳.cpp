#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	cin>>x;
	double a=0.0;
	for(int i=1;;++i)
	{
		a=a+2*pow(0.98,i-1); 
		if(a>=x)
		{
			cout<<i;
			break;
		}
	}
	return 0;
} 
