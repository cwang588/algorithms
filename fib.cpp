#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	a[1]=1;
	a[2]=1;
	for(int i=3;i<=20;++i)
		a[i]=a[i-1]+a[i-2];
	for(int i=1;i<=20;++i)
		cout<<a[i]<<endl;
	return 0;
}
