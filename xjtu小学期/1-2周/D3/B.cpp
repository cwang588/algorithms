#include<bits/stdc++.h>
using namespace std;
long long sum[1000005];
int num[1000005];
int n;
int lowbit(int x)
{
	return x&(-x);
}
long long query(int x)
{
	long long re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
void modify(int x,long long k)
{
	while(x<=1000000)
	{
		sum[x]+=k;
		x+=lowbit(x);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&num[i]);
	for(int i=n;i>=1;--i)
	{
		ans+=query(num[i]-1);
		modify(num[i],1);
	}
	cout<<ans;
	return 0;
}
