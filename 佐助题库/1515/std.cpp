#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int n,m;
bool judge(int x)
{
	int l=1,r=m;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(b[mid]>x)r=mid;
		else l=mid;
	}
	if(b[l]==x||b[r]==x)return true;
	return false;
}
int main()
{
//	freopen("in10.in","r",stdin);
//	freopen("out10.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;++i)
	{
		if(judge(a[i]))
			printf("%d ",a[i]);
	}
	return 0;
}
