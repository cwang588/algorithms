#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	cin>>x;
	double dis=0.0;
	for(int i=1;;++i)
	{
		dis=dis+2*pow(0.98,i-1);
		if(dis>=x)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
