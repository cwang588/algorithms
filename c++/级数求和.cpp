#include<iostream>
using namespace std;
int main()
{
	double tot=0.0;
	int k;
	cin>>k;
	int i;
	for(i=1;;i++)
	{
		tot+=1.0/i;
		if(tot>k)
		{
			cout<<i;
			break;
		}
	}
	return 0;
} 
