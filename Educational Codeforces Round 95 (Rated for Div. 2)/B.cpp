#include<bits/stdc++.h>
using namespace std;
int a[10005],l[10005],tmp[10005];
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
		for(int i=1;i<=n;++i)scanf("%d",&l[i]); 
		int cnt=0;
		for(int i=1;i<=n;++i)if(!l[i])tmp[++cnt]=a[i];
		sort(tmp+1,tmp+1+cnt,cmp);
		int now=0;
		for(int i=1;i<=n;++i)
		{
			if(!l[i])printf("%d ",tmp[++now]);
			else printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}
