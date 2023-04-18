#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[100005];
bool check(int x)
{
	int nowpos=-1000000005,num=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]-nowpos>=x)
		{
			++num;
			nowpos=a[i];
		}
		if(num>=c)return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=1,r=1000000000;
	sort(a+1,a+1+n);
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(r))printf("%d",r);
	else printf("%d",l);
	return 0;
}
