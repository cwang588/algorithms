#include<cstdio>
using namespace std;
long long mi(int x)
{
	long long ans=1;
	if(x==0)
		return 1;
	if(x==1)
		return 3;
	if(x%2)
		ans=(mi(x/2)*mi(x/2)*3)%998244353;
	else
		ans=(mi(x/2)*mi(x/2))%998244353;
	return ans;
}
int main()
{
	int m;
	scanf("%d",&m);
	printf("%lld",mi(m)%998244353);
	
	return 0;
}
