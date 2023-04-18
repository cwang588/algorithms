#include<cstdio>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	long long cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>a[i-1])
			cnt+=a[i]-a[i-1];	
	}		
	printf("%lld",cnt);	
	return 0;
}
