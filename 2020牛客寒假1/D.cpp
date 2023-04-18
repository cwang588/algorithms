#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	long long tot=n*(n+1)/2;
	--n;
	while(n--)
	{
		long long t;
		cin>>t;
		tot-=t;
	}
	cout<<tot<<endl;
	return 0;
}
