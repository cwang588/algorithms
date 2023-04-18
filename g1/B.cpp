#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],aa[100005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&aa[i]);
		a[i]=aa[i]-aa[i-1];
	}
	sort(a+2,a+1+n);
	long long ans=n;
	for(int i=2;i<=n-k+1;++i)
		ans+=a[i]-1;
	printf("%I64d",ans);
	return 0;
}
