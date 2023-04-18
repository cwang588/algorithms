#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		++a[l];
		--a[r+1];
	}
	for(int i=1;i<=n;++i)
	{
		a[i]+=a[i-1];
		printf("%d ",a[i]);
	}
	return 0;
}
