#include<bits/stdc++.h>
using namespace std;
long long a[50];
int main()
{
	for(int i=1;i<=30;++i)
		cin>>a[i];
	sort(a+1,a+31);
	for(int i=1;i<=30;++i)
		cout<<a[i]<<' ';
	return 0;
} 
