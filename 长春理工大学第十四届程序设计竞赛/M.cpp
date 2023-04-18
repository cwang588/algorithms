#include<bits/stdc++.h>
using namespace std;
char t[100005];
int main()
{
	cin>>(t+1);
	int l=strlen(t+1);
	long long num1=0,num2=0,num3=0;
	for(int i=1;i<=l;++i)
	{
		if(t[i]=='x')
			++num1;
		else if(t[i]=='r')
			++num2;
		else
			++num3;
	}
	return 0;
}
