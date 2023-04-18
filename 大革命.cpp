#include<bits/stdc++.h>
using namespace std;
char a[10005];
int main()
{
	while(cin>>a)
	{
		int num1=0,num2=0,l=strlen(a);
		for(int i=0;i<l;++i)
		{
			if(a[i]=='(')
				++num1;
			else
				++num2;
		}
		if(num1==num2)
			printf("YES\n");
		else
			printf("No\n");
	}
	
	
	return 0;
}
