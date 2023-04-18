#include<bits/stdc++.h>
using namespace std;
map<int,bool>usd;
int a[100005],b[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i]; 
	for(int i=1;i<=m;++i)cin>>b[i],usd[b[i]]=true;
	for(int i=1;i<=n;++i)
	{
		if(usd[a[i]])
			printf("%d ",a[i]);
	} 
	printf("\n");
	return 0;
}
