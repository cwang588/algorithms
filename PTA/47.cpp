#include<cstdio>
#include<algorithm>
using namespace std;
int tot[10005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;++i)
	{
		int Max=0,Min=9999;
		for(int j=1;j<=k;++j)
		{
			int t;
			scanf("%d",&t);
			tot[i]+=t;
			Max=max(Max,t);
			Min=min(Min,t);
		}
		tot[i]-=Max+Min;
	}
	sort(tot+1,tot+1+n,cmp);
	for(int i=m;i>1;--i)
		printf("%.3lf ",(double)tot[i]/(double)(k-2));
	printf("%.3lf",(double)tot[1]/(double)(k-2));
	return 0;
}
