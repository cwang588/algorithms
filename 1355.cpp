#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int Max=0,now=1;
	for(int i=2;i<=n;++i)
	{
		if(a[i]<=2*a[i-1])
		{
			++now;
			Max=max(Max,now);
		}
		else
			now=1;
	}
	printf("%d",Max);
	return 0;
}
