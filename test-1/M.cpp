#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
			cout<<i<<"*"<<j<<"="<<i*j<<"\t";
		cout<<"\n";
	}
	return 0;
}
