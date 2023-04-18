#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==1||n==2)
		cout<<"1.00";
	else if(n==0)
		cout<<"0.00";
	else
	{
		long long a=1,b=1,c;
		for(int i=1;i<=n-2;++i)
		{
			c=a+b;
			a=b;
			b=c;
		}
		cout<<c<<".00";
	}
	return 0;
}
