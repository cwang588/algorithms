#include<bits/stdc++.h>
using namespace std;
bool is_Prime(int n)
{
	if(n==1)
		return false;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int n;
		cin>>n;
		if(is_Prime(n)==true)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;	
	}
	return 0;
}
