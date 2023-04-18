#include<bits/stdc++.h>
using namespace std;
int a[5005],ans[5005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		a[i]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;i*j<=n;++j)
			a[i*j]*=-1;
	} 
	int tot=0;
	for(int i=1;i<=n;++i)
		if(a[i]==-1)
		{
			++tot;
			ans[tot]=i;
		}
	for(int i=1;i<tot;++i)
		cout<<ans[i]<<',';
	cout<<ans[tot];
	return 0;
}
