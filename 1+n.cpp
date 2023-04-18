#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x=0;
	cin>>n;
	for(int i=1;i<=n;++i)
		x+=i;
	int i=1;
	while(i<=n)
	{
		x+=i;
		++i; 
	}
	
		cout<<x;
	return 0;
}
