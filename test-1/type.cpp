#include<bits/stdc++.h>
using namespace std;
const long long mod=20200821;
char s[500005];
int main()
{
	cin>>(s+1);
	int n=strlen(s+1);
	long long ans=0;
	long long now=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='1')++now;
		else
		{
			ans=(ans+now*(now+1)/2)%mod;
			now=0;
		}
	}
	ans=(ans+now*(now+1)/2)%mod;
	cout<<ans<<"\n";
	return 0;
}
