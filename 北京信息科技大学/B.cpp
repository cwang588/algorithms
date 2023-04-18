#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=n; 
	for(int i=2;i<=m;++i)
		ans=ans*(n-1)%109;
	printf("%d\n",ans);
	return 0;
}
