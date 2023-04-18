#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int ans[200005];
int main()
{
	int n;	
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)cin>>a[i];

	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
