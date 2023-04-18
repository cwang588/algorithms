#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%100==0)
	{
		if(n%400==0)
		cout<<"yes";
		if(n%400!=0)
		cout<<"no"; 
	}
	if(n%100!=0)
	{
		if(n%4==0)
		cout<<"yes";
		if(n%4!=0)
		cout<<"no"; 
	}
	return 0;
}
