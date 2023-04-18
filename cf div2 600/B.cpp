#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans[1000005];
int usd[1000005],zz[1000005],cnt;
int tep[1000005],num;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int now=0,nowans=0;
	for(int i=1;i<=n;++i)
	{
		++nowans;
		if(a[i]>0)
		{
			if(zz[a[i]]||usd[a[i]])return !printf("-1\n");
			zz[a[i]]=1;
			++cnt;
			usd[a[i]]=1;
			tep[++num]=a[i];
		}
		else
		{
			if(!zz[-a[i]])return !printf("-1\n");
			else zz[-a[i]]=0,--cnt;
		}
		if(!cnt)
		{
			ans[++now]=nowans;
			nowans=0;
			for(int j=1;j<=num;++j)
			{
				usd[tep[j]]=0;
				tep[j]=0;
			}
			num=0;
		}
	}
	if(cnt)return !printf("-1\n");
	printf("%d\n",now);
	for(int i=1;i<=now;++i)printf("%d ",ans[i]);
	return 0;
} 
