#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		string t;
		int a,b;
		cin>>t>>a>>b;
		if(a<15||a>20||b<50||b>70)
			cout<<t<<endl;
	}
	return 0;
}
