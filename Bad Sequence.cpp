#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int n;
	scanf("%d",&n);
	cin>>s;
	int num1=0,num2=0;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='(')
			++num1;
		else
			++num2;
		if(num2-num1>=2)	
			return !printf("No\n");
	}
	if(num1==num2)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
