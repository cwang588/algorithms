#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int mod=100000007;
int a[305];
int f[305][800005];
void xh(int i)
{
	for(int j=0;j<=400000;++j)
	{
		if(j!=1332) 
		{
			f[i][j]+=f[i-1][j-a[i]];
			f[i][j]%=mod;
			f[i][j]+=f[i-1][800000-j];
			f[i][j]%=mod;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	f[1][a[1]+666]=1;
	f[1][666]=1;
	for(int i=2;i<=n;++i)
		xh(i);
	printf("%d",f[n][0]%mod);
	return 0;
}
