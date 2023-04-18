#include<bits/stdc++.h>
using namespace std;
int tong[150],sum[155];
bool a[150];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		a[t]=true;
		++tong[t];
		++sum[t];
		int now=t;
		while(tong[now]==2)
		{
			tong[now]=0;
			if(now-1)
				++tong[now-1];
			a[now]=false;
			--now;
		}
		int tt=1;
		while(!tong[tt]&&tt<=20)
			++tt;
		if(tt==21)
		{
			printf("preassigned\n");
			continue;
		}
		for(int i=tt;;++i)
			if(sum[i])
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
