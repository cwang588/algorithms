#include <iostream>
#include <algorithm>
using namespace std;
int n,c;
int a[100001];
bool nai(int x)
{
	int np=-10000005,num=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-np>=x)
		{
		num++;
		np=a[i];
	    }
	    if(num>=c)
	    {
	    	return true;
		}
	}
	return false;
}
int main()
{
	freopen("zz1520.in","r",stdin);
	freopen("zz1520.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++)	
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1000000000;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(nai(mid))
		{
			l=mid;
		}
		else 
		{
			r=mid;
		}
	}
	if(nai(r))
	{
		cout<<r;
	}
	else 
	{
		cout<<l;
	}
	return 0;
}

