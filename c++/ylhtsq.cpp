#include<iostream>
using namespace std;
long long ranran[100];
int main()
{
	int n;
	cin>>n;
	ranran[1]=ranran[2]=1;
	if(n<=2&&n)
		cout<<"1.00";
	else if(!n)
		cout<<"0.00";
	else
	{
		for(int i=1;i<=n-2;++i)
			ranran[i+2]=ranran[i+1]+ranran[i];
		cout<<ranran[n]<<".00";
	}
	return 0;
}
