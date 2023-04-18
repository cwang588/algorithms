#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(n)
	{
		if(n%(1ll*2))return !printf("Bob\n");
		n/=1ll*2;
	}
	printf("Alice\n");
	return 0;
}
