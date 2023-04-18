#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	a[0]=0;
	for(int i=1;i<=100;++i)
	{
		a[i]=a[i-1]^i;
		printf("%d\n",a[i]);
	}
	
	return 0;
}
