#include<bits/stdc++.h>
using namespace std;
int ans;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
void dfs(long long x,long long y)
{
	if(x<=0||y<=0)
		return;
	++ans;
	if(x>y)
	{
		long long tt=x;
		x=y;
		y=tt;
	}
	long long t=x+gcd(x,y);
	if(y%t==0)
		dfs(x,y-y/t*x);
}
int main()
{
	int t,now=1;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		long long a,b;
		scanf("%lld%lld",&a,&b);
		dfs(a,b);
		printf("Case #%d: %d\n",now++,ans);
	}
	return 0;
}
