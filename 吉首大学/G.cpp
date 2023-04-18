#include<bits/stdc++.h>
using namespace std;
char s[100006];
int main()
{
	cin>>(s+1);
	int n=strlen(s+1);
	long long num1=0,num2=0,num3=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='O')
			++num1;
		else if(s[i]=='R')
			num2+=num1;
		else
			num3+=num2;
	}
	printf("%lld",num3);
	return 0;
}
