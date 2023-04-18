#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,n;
	cin>>a>>b>>n;
	n%=3;
	if(n==0)
		printf("%lld\n",a);
	else if(n==1)
		printf("%lld\n",b);
	else
		printf("%lld\n",a^b);
	return 0;
}
