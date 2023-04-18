#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long b,x;
		scanf("%lld%lld",&b,&x);
		printf("%c\n",(b-1)%x==0?'T':'F');
	}
	return 0;
}
