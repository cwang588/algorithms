#include <bits/stdc++.h>
using namespace std;
long long a[50];
bool b[50];
int n,r;
void dfs(int k,int sum)
{
	if(sum>n-r+k)
		return;
	if(k==r)
	{
		for(int i=1;i<r;i++)
			printf("%3d",a[i]);
		printf("%3d\n",sum);
		return;
	}
	a[k]=sum;
	for(int i=sum+1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=true;
			dfs(k+1,i);
			b[i]=false;
		}		
	}
}
int main()
{
	cin>>n>>r;	
	for(int i=1;i<=n-r+1;i++)
		dfs(1,i);
	return 0;
}
