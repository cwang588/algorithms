#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[105],tong[25005];
bool f[25005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		memset(f,false,sizeof(f));
		memset(tong,0,sizeof(tong));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&sum[i]);
			tong[sum[i]]=i;
		}
		int ans=n;
		sort(sum+1,sum+1+n);
		for(int i=1;i<=sum[n];++i)
		{
			for(int j=1;j<=n;++j)
				if(i>sum[j]&&f[i-sum[j]])
				{
					f[i]=true;
					break;
				}
			if(tong[i])
			{
				if(f[i])
					--ans;
				else
					f[i]=true;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
