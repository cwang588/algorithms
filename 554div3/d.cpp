#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
int main()
{
	long long n,k;
	cin>>n>>k;
	a[1]=(2*(n+k)-k*(k-1))/(2*k);
	if(!a[1]||(k<32&&a[1]*(1<<k)<n))
		return !printf("NO");
	for()
	return 0;
}
