#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y) 
{
	if(!b) 
	{
		x=1;
		y=0;
		return a;
	}
	long long d=exgcd(b,a%b,y,x);
	y=y-a/b*x;
	return d;
}
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	long long x,a,y,b,l;
	scanf("%lld%lld%lld%lld%lld",&x,&a,&y,&b,&l);
	long long A=a-b,B=y-x,C=gcd(l,abs(A));
	if(!A||B%C)
		return !printf("-1");
	A/=C;
	B/=C;
	l/=C;
	long long t,n;
	exgcd(A,-l,t,n);
	t*=B;
	n*=B;
	printf("%lld",t%l);
	return 0;
}
