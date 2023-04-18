#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	if(a+b>=2147483648||a+b<-2147483648)printf("overflow\n");
	else printf("ok\n");
	return 0;
}
