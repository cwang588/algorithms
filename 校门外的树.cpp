#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int l,m;
	cin>>l>>m;
	for(int i=0;i<=l;++i)
		a[i]=1;
	for(int i=1;i<=m;++i)
	{
		int A,b;
		cin>>A>>b;
		for(int j=A;j<=b;++j)
			a[j]=0;
	}
	int ans=0;
	for(int i=0;i<=l;++i)
		if(a[i]==1)
			++ans;
	cout<<ans;
	return 0;
}
