#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	for(int i=2;i<=n;++i)
	{
		if(a[i]==a[i-1])
		{
			++ans;
			a[i]=2147483647;
		}
	}
	printf("%d\n",ans);
	return 0;
}
