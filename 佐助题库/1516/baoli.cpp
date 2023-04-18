#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main()
{
	freopen("in.in","r",stdin);
//	freopen("out9.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		long long nowans=2147483647;
		for(int j=1;j<=m;++j)nowans=min(nowans,abs(b[i]-a[j]));
		ans+=nowans; 
	}
	cout<<ans;
	return 0;
}
