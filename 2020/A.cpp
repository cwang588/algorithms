#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
	int t;
	scanf("%d",&t);
	a[1]=1,a[2]=1;
	for(int i=3;i<=83;++i)a[i]=a[i-1]+a[i-2];
	while(t--)
	{
		 int n;
		 scanf("%d",&n);
		 printf("%lld\n",n>0?a[n+3]:1);
	}
	return 0;
}
