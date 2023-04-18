#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)cout<<(char)('A'+(int)abs(i-j));
		cout<<"\n";
	}
	return 0;
}
