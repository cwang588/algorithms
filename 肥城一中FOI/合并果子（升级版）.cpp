#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
queue<long long>q1,q2;
long long getmin()
{
	if(q2.empty())
	{
		int now=q1.front();
		q1.pop();
		return now;
	}
	if(q1.empty())
	{
		int now=q2.front();
		q2.pop();
		return now;
	}
	if(q1.front()<=q2.front())
	{
		int now=q1.front();
		q1.pop();
		return now;
	}
	else
	{
		int now=q2.front();
		q2.pop();
		return now;	
	}
}
int main()
{
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		q1.push(a[i]);
	long long tot=0;
	for(int i=1;i<n;++i)
	{
		long long t1=getmin(),t2=getmin();
		q2.push(t1+t2);
		tot+=t1+t2;
	}
	printf("%lld",tot);
	return 0;
}
