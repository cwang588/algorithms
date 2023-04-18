#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[10005];
int main()
{
	int m=-1;
	int t,n=0;
	while(cin>>t)
	{
		b[++n]=t;
		m=max(m,t);
	}
	a[0]=a[1]=1;
	for(int i=2;i<=m;++i)
		a[i]=a[i-1]+a[i-2];
	for(int i=1;i<=n;++i)
		printf("%d\n",a[b[i]]);
	return 0;
} 
