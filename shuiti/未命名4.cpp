#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,x=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		long long t,s=0;
		cin>>t; 
		while(t)
		{
			s+=t%10;
			t=t/10;
		}
		if(s%6==0)
		   ++x;
	}
	cout<<x;
	return 0;
}
