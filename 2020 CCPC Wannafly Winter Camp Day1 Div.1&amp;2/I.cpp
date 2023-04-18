#include<bits/stdc++.h>
using namespace std;
int a[80005];
struct node
{
	int l,r,num;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	
	return 0;
}
