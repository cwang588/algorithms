#include<cstdio>
using namespace std;
int a[1005],b[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]+b[i]==a[j]&&a[j]+b[j]==a[i])
				return !printf("YE5\n");
	printf("N0\n");
	return 0;
}
