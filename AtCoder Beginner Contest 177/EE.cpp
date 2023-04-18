#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int m[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	int Max=0;
	for(int i=1;i<=n;++i)
	{
		long long now=a[i];
	//	++m[a[i]];
		for(long long j=2;j*j<=now;++j)
		{
			if(now%j==0)
			{
				++m[j];
				if(j*j!=now)++m[now/j];
				while(now%j==0&&now)now/=j;
			}
		}
		if(now)++m[now];
	}
	for(int i=2;i<=1000000;++i)Max=max(Max,m[i]);
	if(Max==1)printf("pairwise coprime\n");
	else if(Max<n)printf("setwise coprime\n");
	else printf("not coprime\n");
	return 0;
}

