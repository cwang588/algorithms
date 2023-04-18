#include<bits/stdc++.h>
using namespace std;
char a[10005];
int main()
{
	while(cin>>(a+1))
	{
		int num1=0,num2=0;
		for(int i=1;i<=strlen(a+1);++i)
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
		memset(a,' ',sizeof(a));
	}
	return 0;
}
