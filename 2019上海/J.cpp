#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
char s[1005];
int main()
{
	freopen("std.in","r",stdin);	
	freopen("db.txt","w",stdout);	
	cout<<"long long db[]={0,"<<endl;
	int tt,ttt;cin>>tt>>ttt;
	for(int i=2;i<=3000;++i)
	{
		int t;
		cin>>t>>s;
		long long now=0;
		int l=strlen(s);
		for(int j=0;j<l;++j)
		{
			now=now*10+(long long)(s[j]-'0');
			now%=mod;
		}
		cout<<now<<',';
	}
	return 0;
}
