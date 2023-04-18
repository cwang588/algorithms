#include<bits/stdc++.h>
using namespace std;
int x[100005];
int n;
int jdz(int x)
{
	return x>0?x:-x;
}
bool check(int t)
{
	int pos=0,tmp;
	bool usd=false;
	for(int i=1;i<=n;++i)
	{
		if(x[i]>0)
		{
			tmp=i;
			break;
		}
		if(jdz(x[i])>t)
		{
			if(usd)
			{
				if(jdz(pos-x[i])>t)
					return false;
			}
			else
			{
				usd=true;
				pos=x[i]+t;
			}
		}
	}	
	for(int i=n;i>=tmp;--i)
	{
		if(x[i]>t)
		{
			if(usd)
			{
				if(jdz(pos-x[i])>t)
					return false;
			}
			else
			{
				usd=true;
				pos=x[i]-t;
			}
		}
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&x[i]);
		sort(x+1,x+1+n);
		int l=0,r=1000000009;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(check(m))r=m;
			else l=m;
		}
		if(check(l))printf("%d\n",l);
		else printf("%d\n",r);
	}
	return 0;
} 
