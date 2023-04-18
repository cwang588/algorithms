#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	scanf("%d",&x);
	int ans=2147483645;
	for(int i=0;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			b[j]=a[j];
		for(int j=1;j<=i;++j)
			b[j]+=x;
		for(int j=i+1;j<=n;++j)
			b[j]-=x;
		sort(b+1,b+1+n);
		ans=min(ans,b[n]-b[1]);
	}
	printf("%d",ans);
	return 0;
}
