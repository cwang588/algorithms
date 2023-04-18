#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool usd[405];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		usd[a[i]]=true;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&b[i]);
		usd[b[i]]=true;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!usd[a[i]+b[j]])
				return !printf("%d %d",a[i],b[j]);
	return 0;
}
