#include<cstdio>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	long long sum=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>a[i-1])
			sum+=a[i]-a[i-1];
	}
	printf("%lld",sum);
	return 0;
} 
