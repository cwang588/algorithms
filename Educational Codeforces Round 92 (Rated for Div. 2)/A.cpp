#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x,y;
		cin>>x>>y;
		if(x*2>y)cout<<"-1 -1\n";
		else cout<<x<<' '<<2*x<<"\n";
	}
	return 0;
}
