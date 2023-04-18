#include<bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
	a[1]=1;
	printf("1 ");
	for(int i=2;i<=101;++i)
	{
		for(int j=1;j*2<=i;++j)
			a[i]+=a[j];
		++a[i];
		printf("v.push_back(%d);\n ",a[i]);
	}
	return 0;
}
