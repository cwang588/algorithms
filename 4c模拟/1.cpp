#include<cstdio>
using namespace std;
int num[100005];
int ans[100005];
int q[100005];
bool usd[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			int t;
			scanf("%d",&t);
			if(k>1)
				++num[t];
		}
	}
	int m,sum=0;
	bool you=false;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(!usd[t])
		{
			q[++sum]=t;
			usd[t]=true;
		}
	}
	int ansn=0;
	for(int i=1;i<=sum;++i)
		if(!num[q[i]])
		{
			ans[++ansn]=q[i];
			you=true;
		}
	if(!you)
		return !printf("No one is handsome\n");
	for(int i=1;i<ansn;++i)
		printf("%d ",ans[i]);
	printf("%d",ans[ansn]);
	return 0;
}
