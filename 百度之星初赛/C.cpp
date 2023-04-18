#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		if(m>n/2)m=n/2;
		cout<<(n*2-m*2-1)*m<<"\n";
	}
	return 0;
}
