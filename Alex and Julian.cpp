#include<bits/stdc++.h>
using namespace std;
int cnt[200005];
int num[200005];
long long ans[200005];
int main()
{
	int n;
	scanf("%d",&n);
	int Max=0,sum;
	for(int i=1;i<=n;++i)
	{
		cin>>ans[i]; 
		long long t=ans[i];
		int tt=0;
		while(t&&t%2==0)
		{
			t/=2;
			++tt;
		}
		cnt[i]=tt;
		++num[tt];
		if(num[tt]>Max)
		{
			Max=num[tt];
			sum=tt;
		}
	}
	int nnum=0;
	for(int i=1;i<=n;++i)if(cnt[i]!=sum)++nnum;
	printf("%d\n",nnum);
	for(int i=1;i<=n;++i)if(cnt[i]!=sum)printf("%I64d ",ans[i]);
	return 0;
}
