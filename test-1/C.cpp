#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int t;
		cin>>t;
		if(t%2)++ans;
	}
	cout<<ans<<' '<<n-ans<<"\n";
	return 0;
}

