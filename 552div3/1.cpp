#include<cstdio>
#include<algorithm>
using namespace std;
int a[5];
int main()
{
	for(int i=1;i<=4;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+5);
	for(int i=1;i<=3;++i)
		printf("%d ",a[4]-a[i]);
	return 0;
}
