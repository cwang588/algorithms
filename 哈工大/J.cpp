#include<bits/stdc++.h>
using namespace std;
long long mlgb=748683265,Mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		cin>>x;
		long long ans=1;
		ans=(((x%Mod)*((x-1)%Mod))%Mod)*mlgb%Mod;
		cout<<ans<<endl;
	}
	return 0;
}
