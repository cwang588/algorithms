#include<bits/stdc++.h>
using namespace std;
int jc(int n)
{
	if(n==0)
		return 1;
	return n*jc(n-1);
}
int main()
{
	int n;
	cin>>n;
	cout<<jc(n);
	return 0;
}
