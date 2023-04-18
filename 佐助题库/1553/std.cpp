#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int n,k;
bool mc(int x)
{
	long long tot=0;
	for(int i=1;i<=n;i++)	
	{
		tot+=a[i]/x;
	}
	if(tot>=k)
	{
		return true;
	}
	else{
		return false;
	}
}
int main()
{
//	freopen("10.in","r",stdin);
//	freopen("10.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=100000000;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(mc(mid)) l=mid;
		else
		{
			r=mid;
		}
	}
	if(mc(r))
		cout<<r;
	else cout<<l;
	return 0;
}
