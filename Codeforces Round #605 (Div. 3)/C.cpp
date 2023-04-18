#include<bits/stdc++.h>
using namespace std;
char s[200005];
bool usd[27];
int main()
{
	int n,m;
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=m;++i)
	{
		char t;
		cin>>t;
		usd[t-'a']=true;
	}
	long long ans=0;
	long long now=0;
	for(int i=1;i<=n;++i)
	{
		if(!usd[s[i]-'a'])
		{
			ans+=now*(now+1)/2;
			now=0;
		}
		else ++now;
	}
	ans+=now*(now+1)/2;
	cout<<ans<<endl;
	return 0;
}
