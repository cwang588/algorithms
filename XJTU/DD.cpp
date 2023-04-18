#include<bits/stdc++.h>
using namespace std;
int f[10005];
int main()
{
	f[1]=f[2]=1;
	printf("1 1\n2 1\n"); 
	for(int i=3;i<=50;++i)
	{
		f[i]=f[i-1]+f[i-2];
		printf("%d %d\n",i,f[i]);
	}
	return 0;
}
