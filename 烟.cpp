#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,s=0;
	cin>>n>>k;
	s=n;
	while(k<=n)
	{
		s+=n/k;
		n=n/k+n%k;	
	}
	cout<<s;
	
	return 0;
}
