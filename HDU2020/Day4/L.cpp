#include<bits/stdc++.h>
using namespace std;
int a[20050][20050];
void dfs(int x,int y,int z)
{
	if(z<=0)return;
	if(a[x][y+1]!=z-4)dfs(x,y+1,z-4);
	if(a[x-1][y]!=z-3)dfs(x-1,y,z-3);
	if(a[x+1][y]!=z-2)dfs(x+1,y,z-2);
	if(a[x][y-1]!=z-1)dfs(x,y-1,z-1);
	printf("%d %d %d\n",x,y,z);
	a[x][y]=z;
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(10000,10000,n);
	return 0;
}
