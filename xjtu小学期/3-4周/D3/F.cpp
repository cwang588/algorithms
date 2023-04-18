#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int n,m;
bool judge(long long Max)
{
	int num=0;
	long long tot=0;
	for(int i=1;i<=n;++i)
	{
		if(tot+a[i]>Max)
		{
			++num;
			tot=a[i];
		}
		else
			tot+=a[i];
	}
	if(num<=m-1)
		return true;
	else
		return false;
}
int main()
{
	long long M=0,t=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		t+=a[i];
		M=max(M,a[i]);
	}
	long long l=M,r=t;
	while(l<r-1)
	{
		long long mid=(l+r)>>1;
		if(judge(mid))
			r=mid;
		else
			l=mid;
	}
	if(judge(l))
		printf("%lld",l);
	else
		printf("%lld",r);
	return 0;
}
