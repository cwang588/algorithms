#include<bits/stdc++.h>
using namespace std;
int a[1055];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
