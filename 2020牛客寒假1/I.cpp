#include<bits/stdc++.h>
using namespace std;
char s[300005];
bool usd[300005][3];
bool judgenico(int x)
{
	if(s[x]=='o'&&s[x-1]=='c'&&s[x-2]=='i'&&s[x-3]=='n')return true;
	return false;
}
bool judgeniconi(int x)
{
	if(s[x]=='i'&&s[x-1]=='n'&&s[x-2]=='o'&&s[x-3]=='c'&&s[x-4]=='i'&&s[x-5]=='n')return true;
	return false;
}
bool judgeniconiconi(int x)
{
	if(s[x]=='i'&&s[x-1]=='n'&&s[x-2]=='o'&&s[x-3]=='c'&&s[x-4]=='i'&&s[x-5]=='n'&&s[x-6]=='o'&&s[x-7]=='c'&&s[x-8]=='i'&&s[x-9]=='n')return true;
	return false;
}
long long dp[300005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	long long a,b,c;
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;++i)cin>>s[i];
	if(n<4)return !printf("0\n");
	for(int i=1;i<=n;++i)
	{
		if(i>=4)usd[i][0]=judgenico(i);
		if(i>=6)usd[i][1]=judgeniconi(i);
		if(i>=10)usd[i][2]=judgeniconiconi(i);
	}
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1];
		if(usd[i][0])dp[i]=max(dp[i],dp[i-4]+a);
		if(usd[i][1])dp[i]=max(dp[i],dp[i-6]+b);
		if(usd[i][2])dp[i]=max(dp[i],dp[i-10]+c);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
