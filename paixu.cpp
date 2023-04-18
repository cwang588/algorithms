#include<bits/stdc++.h>
using namespace std;
int a[15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	return 0;
}
