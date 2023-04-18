#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
string num[25];
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
		cin>>num[i];
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;++i)
		cout<<num[i];
	return 0;
}
