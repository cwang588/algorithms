#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char t[55];
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		memset(t,' ',sizeof(t));
		cin>>t;
		int l=strlen(t);
		long long n=0;
		for(int i=0;i<l;++i)
			n=(n*10+t[i]-'0')%mod;
		long long ans=((((n*n)%mod*n)%mod+n*5%mod+6)%mod*166666668)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
