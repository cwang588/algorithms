#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long num[200005];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n>>(s+1);
		int now=0,numnow=1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]==s[i+1]&&i!=n)++numnow;
			else num[++now]=numnow,numnow=1;
		}
		if(now==1)
		{
			printf("%lld\n",(long long)(n-1)/3+1);
			continue;
		} 
		if(s[1]==s[n])num[now]+=num[1],num[1]=0;
		long long ans=0;
		for(int i=1;i<=now;++i)ans+=num[i]/3;
		printf("%lld\n",ans);
	}
	return 0;
}
