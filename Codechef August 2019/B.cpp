#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%lld%lld",&n,&k);
		if(k==1||n/k%k==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
