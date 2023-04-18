#include<cstdio>
using namespace std;
int a[105],sum[105],num;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
		sum[++num]=i;
	}
	int ans=0,now=1;
	while(now<=num)
	{
		if(sum[now]!=sum[now+1]-2)
		{
			++ans;
			++now;
		}
		else
		{
			int t=1;
			++now;
			while(sum[now]-sum[now-1]==2)
			{
				++now;
				++t;
			}
			if(t%2)
				ans+=(t/2)+1;
			else
				ans+=t/2;
		}
	}
	printf("%d",ans);
	return 0;
}
