#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b)
		swap(a,b);
	if(b%a==0)
		return !printf("0");
	b-=(a-2);
	a=2;
	if(b)
	return 0;
}
