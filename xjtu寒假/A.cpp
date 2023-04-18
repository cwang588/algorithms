#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1000000007;
int main()
{
	unsigned long long a,b;
	cin>>a>>b;
	a%=mod;
	b%=mod;
	cout<<a*b%mod;
	return 0;
}
