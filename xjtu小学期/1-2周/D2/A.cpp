#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		tot+=a[i];
		if(tot>=m)
			return !printf("%d",tot==m?i:i-1);
	}
	return 0;
}
