#include<bits/stdc++.h>
using namespace std;
const int n=15;
int cnt[20][20];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void dfs(int x,int y)
{
	if(x>n||y>n)
		return;
	++cnt[x][y];
	int l=x*y/gcd(x,y);
	dfs(x+l,y);
	dfs(x,y+l);
}
int main()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dfs(i,j);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",cnt[i][j]);
		printf("\n");
	}
	return 0;
}
