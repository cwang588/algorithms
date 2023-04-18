#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long tt[100005];
bool cmp(long long x,long long y)
{
	return x>y;
}
int n,num;
long long tot,k;
void calc()
{
	int numm=n-num;
	tot=k*n;
	for(int i=numm;i<=n;++i)
		tot+=tt[i];
	cout<<tot<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		tot=0;
		memset(a,0,sizeof(a));
		memset(tt,0,sizeof(tt));
		cin>>n>>k;
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i)
		{
			tt[i]=a[i]%k;
			tot+=a[i];
			num+=a[i]/k;
		}
		sort(tt+1,tt+1+n,cmp);
		if(num>=n-1)
			cout<<k+tot<<endl;
		else
			calc();
	}
	return 0;
}
