#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
	freopen("zz15175.in","w",stdout);
	srand((unsigned)time(NULL));
	int n,m;
	n=m=1000000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)
		a[i]=(rand()*10000+rand())%1000000000+1;
	for(int i=1;i<=n/2;++i)b[i]=a[i];
	sort(a+1,a+1+n);
	for(int i=n/2+1;i<=m;++i)b[i]=(rand()*10000+rand())%1000000000+1;
	for(int i=1;i<=n;++i)printf("%lld ",a[i]);
	printf("\n");
	for(int i=1;i<=m;++i)printf("%lld ",b[i]);
	printf("\n");
	return 0;
}
