#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char t[1000005];
long long quickpower(int a,int b,int p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int main()
{
	while(cin>>t)
	{
		int l=strlen(t);
		long long now=0;
		if(t[0]=='0')
			return 0;
		for(int i=0;i<l;++i)
			now=now*10%(mod-1)+t[i]-'0';
		long long ans=(quickpower(2,now-1,mod)+quickpower(4,now-1,mod))%mod;
		cout<<ans<<endl;
		memset(t,' ',sizeof(t));
	}	
	return 0;
}
