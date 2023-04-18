#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	for(int i=8;i<=100;++i)
		if(gcd(i+7,i-7)==1)
			printf("%d %d %d\n",i-7,i+7,i);
	
	return 0;
}
