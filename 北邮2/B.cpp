#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],sum[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int num=1;
	sum[1]=a[1];
	for(int i=2;i<=n;++i)
		if(a[i]!=a[i-1])
			sum[++num]=a[i];
	if(num>3)
		return !printf("NO");
	if(num<3)
		return !printf("YES");
	if(sum[3]+sum[1]==2*sum[2])
		return !printf("YES");
	printf("NO");
	return 0;
}
