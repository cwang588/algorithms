#include<bits/stdc++.h>
using namespace std;
int sum[100005];
int main()
{
	int n;
	scanf("%d",&n);
	sum[1]=1;
	for(int i=2;i<=n;++i)
	{
		++sum[i];
		for(int j=1;2*j<=i;++j)
			sum[i]+=sum[j],sum[i]%=50000;
	}
	printf("%d\n",sum[n]);
	return 0;
}
