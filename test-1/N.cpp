#include<bits/stdc++.h>
using namespace std;
int a[205][205];
int main()
{
	int n,m;	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cout<<a[n-j+1][i];
			if(j!=n)cout<<' ';
		}
		cout<<"\n";
	}
	return 0;
}
