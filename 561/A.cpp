#include<bits/stdc++.h>
using namespace std;
long long a[500005],N;
int pos(int x)
{
	int l=0,r=N;
	while(l<r-1)
	{
		int m=(l+r)>>1;
		if(a[m]==x)
			return m;
		if(a[m]>x)
			r=m;
		if(a[m]<x)
			l=m;
	}
	return r;
}
int main()
{
	int n,zheng=0,fu=0;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]>0)
			++zheng;
		if(a[i]<0)
			++fu;
	}
	sort(a+1,a+1+n);
	N=unique(a+1,a+1+n)-(a+1);
	long long ans=0;
	for(int i=1;i<N;++i)
	{
		if(a[i]<0)
		{
			if(a[i]*(-2)+1<=a[N])
				ans+=pos(a[i]*(-2)+1)-pos(0);
			else
				ans+=N-pos(0)+1;
			int p=pos(a[i]/2);
			if(p<0)
				ans+=p-i;
			else
				ans+=p-i-1;
		}
		else if(a[i]==0)
			ans+=N-i;
		else
		{
			if(2*a[i]+1<=a[N])
				ans+=pos(2*a[i]+1)-i-1;
			else
				ans+=N-i;
		}
	}
	cout<<ans;
	return 0;
}
