#include<bits/stdc++.h>
using namespace std;
long long a[200005],s[200005],sk[200005];
int n,k;
long long p;
bool judge(int num)
{
	if(num>=k)
	{
		long long tot=s[num%k]+sk[num];
		if(tot<=p)return true;
		return false;
	}
	if(s[num]>p)return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int t; 
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(sk,0,sizeof(sk));
		cin>>n>>p>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
		{
			s[i]=s[i-1]+a[i];
			if(i>=k)sk[i]=sk[i-k]+a[i];	
		}
		if(a[k]>p)
		{
			int l=0,r=k-1;
			while(l<r-1)
			{
				int m=(l+r)>>1;
				if(s[m]<=p)l=m;
				else r=m;
			}
			if(s[r]<=p)printf("%d\n",r);
			else printf("%d\n",l);
			continue;
		}	
		int l=k,r=n;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(judge(m))l=m;
			else r=m;
		}
		if(judge(r))printf("%d\n",r);
		else printf("%d\n",l);
	}
	return 0;
	
}
