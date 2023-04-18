#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,a;
	cin>>n>>m>>a;
	if(a%2)--a;
	long long x,y;
	x=n/a;
	if(n%a)++x;
	y=m/a;
	if(m%a)++y;
	printf("%lld",x*y);
	return 0;
}
