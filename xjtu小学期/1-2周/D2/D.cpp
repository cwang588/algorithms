#include<bits/stdc++.h>
using namespace std;
int cnt[35],wei[35];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t!=1073741824)
		{
			for(int j=0;;++j)
				if((1<<j)&t)
				{
					++cnt[j];
					break;
				}
		}
		else
			++cnt[30];
	}
	while(q--)
	{
		int t;
		scanf("%d",&t);
		memset(wei,0,sizeof(wei));
		int m=0;
		int tt=t;
		for(int j=30;j>=0;--j)
		{
			if(tt>=pow(2,j))
			{
				tt-=pow(2,j);
				++wei[j];
				m=max(m,j);
			}		
		}
		int ans=0;
		for(int i=m;i>=0;--i)
		{
			if(wei[i]<=cnt[i])
				ans+=wei[i];
			else
			{
				if(i)
				{
					ans+=cnt[i];
					wei[i]-=cnt[i];
					wei[i-1]+=2*wei[i];
				}
				else
					ans=-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
