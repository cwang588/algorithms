#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;
int main()
{
	freopen("ha.txt","r",stdin);
	//freopen("jiang.txt","w",stdout);
	char a;
	while(scanf("%c",&a)&&a!='a')cout<<a;
	system("pause");
}

