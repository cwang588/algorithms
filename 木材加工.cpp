#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[100005];
bool check(int x)
{
	long long tot=0;
	for(int i=1;i<=n;++i)tot+=a[i]/x;
	if(tot>=k)return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=0,r=100000000;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(r))printf("%d\n",r);
	else printf("%d\n",l);
	return 0;
}
