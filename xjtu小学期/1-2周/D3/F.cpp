#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	a[n+1]=k;
	int l=0,r=k;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		bool ky=true;
		int tot=0,now=1,lst=0;
		while(now<=n+1)
		{
			while(a[now]-a[lst]<mid&&now<=n+1)
			{
				++now;
				++tot;
			}
			lst=now;
			if(now==n+2)
				ky=false;
			if(now==n)
			{
				if(k-a[now]<m)
					++tot;
			}
			++now;
		}
		if(tot>m)
			ky=false;
		if(ky)
			l=mid;
		else
			r=mid;
	}
	int Mid=r;
	bool ky=true;
	int tot=0,now=1,lst=0;
	while(now<=n+1)
	{
		while(a[now]-a[lst]<Mid&&now<=n+1)
		{
			++now;
			++tot;
		}
		lst=now;
		if(now==n+2)
			ky=false;
		if(now==n)
		{
			if(k-a[now]<m)
				++tot;
		}
		++now;
	}
	if(tot>m)
		ky=false;
	if(ky)
		return !printf("%d",r);
	else
		return !printf("%d",l);
	return 0;
}
