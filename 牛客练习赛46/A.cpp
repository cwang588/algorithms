#include<bits/stdc++.h>
using namespace std;
int ans[1000005],ss[1000005];
int main()
{
	int n,m;
	string s;
	cin>>n>>m>>s;
	int now=0;
	for(int i=0;i<n;++i)
	{
		int t=s[i]-'0';
		if(i+1>m)
			ans[i]=ss[i-1]^ss[i-m]^(t);
		else ans[i]=ss[i-1]^(t);
		now^=ans[i];
		ss[i]=now;
	}
	for(int i=0;i<n;++i)printf("%d",ans[i]);
	return 0;
}
