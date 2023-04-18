#include<bits/stdc++.h>
using namespace std;
int a[1005],s[1005][1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&s[i][j]);
	a[1]=(-s[2][3]+s[1][2]+s[1][3])/2;
	for(int i=2;i<=n;++i)a[i]=s[1][i]-a[1];
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}
