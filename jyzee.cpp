#include<bits/stdc++.h>
using namespace std;
int a[15];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	for(int i=1;i<=5;++i)
		scanf("%d",&a[i]);
	int now=1;
	for(int i=1;i<=5;++i)
		now=now*a[i]/gcd(now,a[i]);
	printf("%d",now);
	return 0;
}
