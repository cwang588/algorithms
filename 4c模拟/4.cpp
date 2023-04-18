#include<cstdio>
#include<iostream>
using namespace std;
struct stu
{
	char name[50];
	int a,b;
}s[15];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		cin>>s[i].name>>s[i].a>>s[i].b;
	for(int i=1;i<=n;++i)
		if(s[i].a<15||s[i].a>20||s[i].b<50||s[i].b>70)
			cout<<s[i].name<<endl;
	return 0;
} 
