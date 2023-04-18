#include<bits/stdc++.h>
using namespace std;
int sum[1000005];
long long num[100005];
void Init(int x)
{
	for(int i=1;i<=x;++i)
	{
		int tmp=i,tot=0;
		while(tmp)
		{
			tot+=tmp%10;
			tmp/=10;
		}
		sum[i]=tot;
		++num[tot];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Init(n);
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=num[sum[i]];
	printf("%lld\n",ans);
	return 0;
}
