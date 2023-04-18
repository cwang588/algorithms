#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	int n;
	char t;
	cin>>n>>t;
	getchar();
	getline(cin,a);
	int l=a.size();
	if(l>=n)
	{
		for(int i=l-n;i<=l-1;++i)
			cout<<a[i];
	}	
	else
	{
		for(int i=1;i<=n-l;++i)
			printf("%c",t);
		cout<<a;
	}
	return 0;
}
