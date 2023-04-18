#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,m;
		long long tot=0;
		scanf("%d%d",&n,&m);
		int num=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(!a[i]) 
				++num;
		}
		sort(a+1,a+1+n);
		if(num>m)
		{
			printf("Impossible\n");
			continue;
		}
		if(m==n)
		{
			printf("Richman\n");
			continue;
		}
		for(int i=1;i<=m;++i)
			tot+=(long long)a[i];
		tot+=(long long)a[m+1]-1;
		printf("%lld\n",tot);
	}
	return 0;
}
