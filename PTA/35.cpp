#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
string t;
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	getchar();
	getline(cin,t);
	int l=t.size();
	if(l>=n)
	{
		for(int i=l-n;i<l;++i)
			printf("%c",t[i]);
	}
	else
	{
		for(int i=1;i<=n-l;++i)
			printf("%c",c);
		cout<<t;
	}
	return 0;
}
