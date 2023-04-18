#include<bits/stdc++.h>
using namespace std;
long long ppow(int a,int b)
{
	long long re=1;
	for(int i=1;i<=b;++i)
		re*=a;
	return re;
}
int main()
{
	long long now=1;
	for(int i=1;i<=16;++i)
		printf("%lld\n",((9*i-1)*ppow(10,i)+1)/9);	
	return 0;
}
