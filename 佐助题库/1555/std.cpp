#include<cstdio>
#include<algorithm>
using namespace std;
int Max=-19260817;
int rr[425][425];
int he[425];
int main()
{
//	freopen("10.in","r",stdin);
//	freopen("10.out","w",stdout);
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int a;
			scanf("%d",&a);
			rr[i][j]=rr[i-1][j]+a;
		}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
				he[k]=rr[j][k]-rr[i-1][k];
			int m=-19260817,tot=0,fu=-19260817;
			for(int k=1;k<=n;++k)
			{
				tot+=he[k];
				m=max(m,tot);
				if(tot<=0)
				{
					tot=0;
					fu=max(fu,tot);
				}
			}
			if(tot==0)
				m=fu;
			Max=max(Max,m);
		}
	printf("%d",Max);
	return 0;
}
