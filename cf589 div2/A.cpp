#include<bits/stdc++.h>
using namespace std;
bool usd[15];
bool judge(int x)
{
	memset(usd,false,sizeof(usd));
	while(x)
	{
		if(usd[x%10])return false;
		usd[x%10]=true;
		x/=10;
	}
	return true;
}
int main()
{
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;++i)
		if(judge(i))
		{
			cout<<i<<endl;
			return 0;
		}
	cout<<"-1\n";
	return 0;
}
