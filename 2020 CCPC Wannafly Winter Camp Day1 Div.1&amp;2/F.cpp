#include<bits/stdc++.h>
using namespace std;
vector<long long>a,b;
long long k;
int n,m;
bool judge(long long x)
{
	long long tot=0;
	for(int i=0;i<n;++i)
	{
		long long now=a[i];
		if(!now)
		{
			if(x>=0)
				tot+=m;
		}
		else if(now>0)
		{
			long long tmp;
			if(x<=0)tmp=x/now;
			else tmp=(x-1)/now+1;
			tot+=(long long)(b.end()-lower_bound(b.begin(),b.end(),tmp));
		}
		else 
		{
			long long tmp;
			if(x<=0)tmp=x/now;
			else tmp=(x-1)/now-1;
			long long t=(long long)(upper_bound(b.begin(),b.end(),tmp)-b.begin());
//			if(t)++t;
			tot+=t;
		}
	}
	return tot<k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;	
	for(int i=1;i<=n;++i)
	{
		long long t;
		cin>>t;
		a.push_back(t);
	}
	for(int i=1;i<=m;++i)
	{
		long long t;
		cin>>t;
		b.push_back(t);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long long l=-2000000000000,r=2000000000000;
	while(l<r-1)
	{
		long long mid=(l+r)>>1;
		if(judge(mid))r=mid;
		else l=mid;
	}
	if(judge(l))cout<<r<<endl;
	else cout<<l<<endl;
	return 0;
}
