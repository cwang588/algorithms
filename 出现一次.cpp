#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t;
	int ans=0;
	while(cin>>t)
		ans^=t;
	printf("%d",ans);
	return 0;
}
