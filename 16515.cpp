#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	for(int i=1;i<=10;++i)
	{
		cin>>a[i];
	}
	int x;
	cin>>x;
	x+=30;
	int t=0;
	for(int i=1;i<=10;++i )
	{
		if(a[i]<=x)
		t++;
	}
	cout<<t;
	return 0;
}
